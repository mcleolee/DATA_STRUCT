#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

lklst_ptr_node create_linklist(void)
{
    lklst_ptr_node L = (lklst_ptr_node)malloc(sizeof(lklst_node));
    if(NULL == L)
    {
        printf("apply for malloc failed\n");
        return NULL;
    }
    //初始化指针，不然野指针必然段错误
    L->next = NULL;
    return L;
}

int insert_linklist(lklst_ptr_node L, int pos, linklist_data_t data)
{
    int len = get_len_linklist(L);
    //因为链表不会满，有一个来一个，所以不用判满
    //判断 pos 是否合法
    if(0 > pos || pos > len)
    {
        printf("position is default\n");
        return -1;
    }

    //找到插入位置的前一个node地址
    for(int i=0; i<pos; i++)//如果在第三个，L 就走到第二位
    {
        L = L->next;
    }

    //插入
    lklst_ptr_node p = create_linklist();   //创建新节点
    p->data = data;                         //初始化新节点

    //???
    p->next = L->next;
    L->next = p;

    return 0;
}

//计算len的长度
int get_len_linklist(lklst_ptr_node L)
{
    int len = 0;
    while(L->next) //如果要再少循环一次：L->next->next
    {
        L = L->next;
        len++;
    }
    return len;
}

//根据’位置‘删除
int delete_linklist(lklst_ptr_node L,int pos)
{
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }
    if(0 > pos || get_len_linklist(L) <= pos)
    {
        printf("position is default\n");
        return -1;
    }

    //找到要删除的前一个node的地址
    for(int i=0; i<pos; i++)
    {
        L = L->next;
    }

    //保存要删除的node地址
    lklst_ptr_node temp = L->next;
    //连线
    L->next = temp->next;

    //释放空间
    free(temp);
    return 0;
}

//判空
int empty_linklist(lklst_ptr_node L)
{
    if(NULL == L->next)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//打印
int show_linklist(lklst_ptr_node L)
{
    //浅浅判空
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }
    
    //遍历打印数组
    while(L->next) //L不能移动到最后一个，不然L->next就是NULL，会段错误
    {
        printf("%c",L->next->data);
        L = L->next;
    }
    printf("\n");
    return 0;
}

//根据值修改
int change_linklist(lklst_ptr_node L,linklist_data_t old_data,linklist_data_t new_data)
{
    //判空
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }

    int flag = 0;
    while(L->next)
    {
        if(old_data == L->next->data)
        {
            flag = 1;
            break; //跳出来的时候指的是前一个
        }
            
        L = L->next;
    }

    if(1 == flag)
    {
        L->data = new_data;
    }
    else
    {
        printf("no find data\n");
        return -1;
    }
    return 0;
}


//摧毁
int destory_linklist(lklst_ptr_node *L)
{
    //判空
    if(0 == empty_linklist(*L))
    {
        free(*L);
        return 0;
    }   


    clean_linklist(*L);
    // puts("phase 1");
    free(*L);
    *L = NULL;
    // puts("phase 2");

    return 0;
}


//清空
int clean_linklist(lklst_ptr_node L)
{
    //判空
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }
    lklst_ptr_node p = L;
    lklst_ptr_node temp = L->next;
    while(temp)
    {
        L = temp;
        temp = L->next;
        free(L);
    }
    L->next = NULL;
    return 0;
}


//逆序
int reversed_order_linklist(lklst_ptr_node L)
{
    //判空
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }

    //分成两个链表
    lklst_ptr_node p = L->next;
    lklst_ptr_node ap = p;
    L->next = NULL;

    //把 p 指向的链表依次对 L 指向的链表做头插
    while(p)
    {
        //向后移一位
        ap = p;
        p = p->next;
        
        //在做头插
        ap->next = L->next;
        L->next = ap;
    }
}


//排序
int sort_linklist(lklst_ptr_node L)
{
    //判空
    if(0 == empty_linklist(L))
    {
        printf("L is empty\n");
        return -1;
    }

    //分成两个链表
    lklst_ptr_node p = L->next;
    lklst_ptr_node ap = p;
    lklst_ptr_node temp = L;

    int flag = 0;

    L->next = NULL;

    //把 p 指向的链表依次对 L 指向的链表做头插
    while(p)
    {
        //向后移一位
        ap = p;
        p = p->next;

        //有序插入
        temp = L;
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
