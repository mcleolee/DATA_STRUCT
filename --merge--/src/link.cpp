#include <stdio.h>
#include <stdlib.h>
#include "link.h"

#if 1

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//                   LIST
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

lkdlst_ptr_node create_linkedList(void)
{
    lkdlst_ptr_node LL = (lkdlst_ptr_node)malloc(sizeof(lkdlst_node));
    if(NULL == LL)
    {
        printf("Apply for malloc failed\n");
        // 也可以
        // memset(head->data,0,sizeof(head->data));// 或 bzero();
        return NULL;
    }
    //初始化指针，不然野指针必然段错误
    LL->next = NULL;
    
    return LL;
    
}

// 量长度
int get_length_linkedList(lkdlst_ptr_node LL)
{
    int len = 0;
    while(LL->next)
    {
        LL = LL->next;
        len++;
    }
    return len;
}

// 判空
int empty_linkedList(lkdlst_ptr_node LL)
{
    if(NULL == LL->next)
    {
        printf("LL is on the end of the list\n");
        return 0;
    }
    else
    {
        return -2;
    }
}

// 打印
int print_linkedList(lkdlst_ptr_node LL)
{
    //浅浅判空
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        printf("LL is on the end of the list\n");
        return -1;
    }
    printf("\nThe linked list is \n\t");
    //遍历打印数组
    while(LL->next) //L不能移动到最后一个，不然L->next就是NULL，会段错误
    {
        printf("%c ",LL->next->data);
        LL = LL->next;
    }
    printf("\n");
    return 0;
}

// 插入
int insert_linkedList(lkdlst_ptr_node LL,int pos, linkedList_data_type ISTdata)
{
    int len = get_length_linkedList(LL);
    //因为链表不会满，有一个来一个，所以不用判满
    //判断 pos 是否合法
    if(0 > pos || pos > len)
    {
        perror("Fatal:The position you ask is wrong\n");
        return -1;
    }
    //让LL到pos前，这样新节点就在LL和LL->next之间
    for(int i=0;i<pos;i++)
    {
        LL = LL->next;
    }
    //创建新节点
    lkdlst_ptr_node ptr_new_node = create_linkedList();

    //把插入的数据给新节点
    ptr_new_node->data = ISTdata;

    //把新node和前后节点连接起来
    ptr_new_node->next = LL->next;
    LL->next = ptr_new_node;

    return 0;

}

// 删除
int delete_based_address_linkedList(lkdlst_ptr_node LL, int pos)
{
    if(0 == empty_linkedList(LL))
    {
        printf("error: This linked list is empty.\n");
        return -1;
    }

    // position 要是比表还长肯定逆天
    if(pos < 0 || get_length_linkedList(LL) <= pos)
    {
        printf("error: bad position.\n");
        return -2;
    }

    //找到要删除的前一个node的地址
    for(int i=0;i<pos-1;i++)
    {
        LL = LL->next;
    }

    //保存要删除的node地址
    lkdlst_ptr_node temp = LL->next;
    //连线
    LL->next = temp->next;

    //释放空间
    free(temp);
    return 0;
}

// 根据值修改
int change_linkedList(lkdlst_ptr_node LL,linkedList_data_type OLDdata,linkedList_data_type NEWdata)
{
    //浅浅判空
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        printf("LL is on the end of the list\n");
        return -1;
    }

    int flag = 0;
    while(LL->next)
    {
        if(OLDdata == LL->next->data)
        {
            flag = 1;
            break; // 跳出来的时候指的是前一个
        }
        LL = LL->next;
    }

    if(1 == flag)
    {
        LL->next->data = NEWdata;
    }
    else
    {
        printf("error:No data find.\n");
        return -2;
    }
    return 0;
}

//摧毁
int destory_linkedList(lkdlst_ptr_node *LL)
{
    if(0 == empty_linkedList(*LL))
    {
        free(*LL);
        return 0;
    }

    clean_linkedList(*LL);
    // puts("phase 1");
    free(*LL);
    *LL = NULL;
    // puts("phase 2");

    return 0;
}

//清空
int clean_linkedList(lkdlst_ptr_node LL)
{
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        return -1;
    }
    lkdlst_ptr_node p = LL;
    lkdlst_ptr_node temp = LL->next;
    while(temp)
    {
        LL = temp;
        temp = LL->next;
        free(LL);
    }
    LL->next = NULL;
    return 0;
}

//逆序
int reversed_order_linkedList(lkdlst_ptr_node LL)
{
    //判空
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        printf("LL is on the end of the list\n");
        return -1;
    }

    //分成两个链表
    lkdlst_ptr_node p = LL->next;
    lkdlst_ptr_node ap = p; // ap meaning after p?
    LL->next = NULL;

    //把 p 指向的链表依次对 LL 指向的链表做头插
    while(p)
    {
        //向后移一位
        ap = p;
        p = p->next;
        
        //再做头插
        ap->next = LL->next;
        LL->next = ap;
    }



}

//排序
int sort_linkedList(lkdlst_ptr_node LL)
{
    //判空
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        printf("LL is on the end of the list\n");
        return -1;
    }
    //分成两个链表
    lkdlst_ptr_node p = LL->next;
    lkdlst_ptr_node ap = p;
    lkdlst_ptr_node temp = LL;

    int flag = 0;

    LL->next = NULL;

    //把 p 指向的链表依次对 LL 指向的链表做头插
    while(p)
    {
        //向后移一位
        ap = p;
        p = p->next;

        //有序插入
        temp = LL;
        while(temp->next)
        {
            if(temp->next->data > ap->data)
            {
                ap->next = temp->next;
                temp->next = ap;
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 0)
        {
            //说明是最大的所以没插，作尾插
            temp->next = ap;
            ap->next = NULL;
        }
        flag = 0;
    }
    return 0;
}
#endif // list

#if 1
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//                  QUEUE
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//++++++++++++++++++++++++++++++++++++++++++
//  lkdq_ptr_node 是给 front 和 rear 的
//    ptr_node 是给 next 和 data 的
//++++++++++++++++++++++++++++++++++++++++++
lkdq_ptr_node create_linkedQueue()
{
    // 创建头节点
    ptr_node H = (ptr_node)malloc(sizeof(node));
    if(NULL == H)
    {
        printf("Error: memory allocate failed\n");
        return NULL;
    }
    // 初始化
    H->next = NULL;

    //创建???
    lkdq_ptr_node LQ = (lkdq_ptr_node)malloc(sizeof(lkdq_node));
    if(NULL == LQ)
    {
        printf("Error: memory allocate 2th failed\n");
        return NULL;
    }
    LQ->front = LQ->rear = H;
}

//出入队
int enter_linkedQueue(lkdq_ptr_node LQ,linkedQueue_data_type NEWdata)
{
    ptr_node p = (ptr_node)malloc(sizeof(node)); //不能用create函数捏
    if(NULL == p)
    {
        printf("Error: memory allocate failed\n");
        return -1;
    }
    p->data = NEWdata;

    p->next = NULL;
    LQ->rear->next = p;
    LQ->rear = p;

    return 0;
}

linkedQueue_data_type exit_linkedQueue(lkdq_ptr_node LQ)
{
    if(0 == empty_linkedQueue(LQ))
    {
        printf("the queue is empty\n");
        return -1;
    }

    ptr_node p = LQ->front->next;
    LQ->front->next = p->next;

    linkedQueue_data_type data = p->data;
    //在free之前判断
    if(p->next == NULL)
    {
        LQ->rear = LQ->front;
    }
    free(p);
    return p->data;
}

//判空满
int empty_linkedQueue(lkdq_ptr_node LQ)
{
    if(LQ->front == LQ->rear)
    {
        // printf("the queue is empty\n");
        return 0;
    }
    else
    {
        return -1;
    }
}

//打印
int print_linkedQueue(lkdq_ptr_node LQ)
{
    if(0 == empty_linkedQueue(LQ))
    {
        printf("Error: the queue is empty\n");
        return -1;
    }
    //顺着打印过来，和链表打印没什么区别
    ptr_node temp = LQ->front;
    printf("\nThe linked queue is \n\t");
    while(temp->next)
    {
        printf("%c ",temp->next->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}











#endif