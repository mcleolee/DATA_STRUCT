#include <stdio.h>
#include <stdlib.h>
#include "link.h"


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
        printf("LL is on the end of the list\n");
        return -2;
    }
    
    //遍历打印数组
    while(LL->next) //L不能移动到最后一个，不然L->next就是NULL，会段错误
    {
        printf("%c ",LL->next->data);
        LL = LL->next;
    }
    printf("\n");
    return 0;
}



int insert_linkedList(lkdlst_ptr_node LL,int pos, linkedList_data_type ISTdata)
{
    int len = get_length_linkedList(LL);
    //因为链表不会满，有一个来一个，所以不用判满
    //判断 pos 是否合法
    if(0 > pos || pos > len)
    {
        printf("Fatal:The position you ask is wrong\n");
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