#include "linkedQueue.h"
#include <stdlib.h>
#include <stdio.h>
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// lkdq_ptr_node 是给 front 和 rear 的
// ptr_node 是给 next 和 data 的
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
lkdq_ptr_node create_linkedQueue() // check!    checked,ok.
{
    //创建头节点
    ptr_node H = (ptr_node)malloc(sizeof(node));
    if(NULL == H)
    {
        printf("malloc apply failed\n");
        return NULL;
    }
    H->next = NULL;


    //创建???
    lkdq_ptr_node Q = (lkdq_ptr_node)malloc(sizeof(lkdq_node));
    if(NULL == Q)
    {
        printf("malloc 2 apply failed\n");
        return NULL;
    }
    Q->front = Q->rear = H;
}


//出入队
int enter_linkedQueue(lkdq_ptr_node Q,linkedQueue_data_type newData)
{
    ptr_node p = (ptr_node)malloc(sizeof(node)); //不能用create函数捏
    if(NULL == p)
    {
        printf("malloc apply failed\n");
        return -1;
    }
    p->data = newData;

    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;

    return 0;
}

linkedQueue_data_type exit_linkedQueue(lkdq_ptr_node Q)
{
    if(0 == empty_linkedQueue(Q))
    {
        printf("the queue is empty\n");
        return -1;
    }

    ptr_node p = Q->front->next;
    Q->front->next = p->next;

    linkedQueue_data_type data = p->data;
    //在free之前判断
    if(p->next == NULL)
    {
        Q->rear = Q->front;
    }
    free(p);

}

//判空满
int empty_linkedQueue(lkdq_ptr_node Q)
{
    if(Q->front == Q->rear)
    {
        // printf("the queue is empty\n");
        return 0;
    }
    else
    {
        return -1;
    }
}

// int  full_linkedQueue(lkdq_ptr_node Q);

//打印
int show_linkedQueue(lkdq_ptr_node Q)
{
    if(0 == empty_linkedQueue(Q))
    {
        printf("the queue is empty\n");
        return -1;
    }
    //顺着打印过来，和链表打印没什么区别
    ptr_node temp = Q->front;
    while(Q->front)
    {
        printf("%c",temp->next->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

