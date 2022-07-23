#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H

// #define N 1024

typedef char linkedQueue_data_type;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//结构体
typedef struct node
{
    linkedQueue_data_type data;
    struct node *next;
}node,*ptr_node;

//指向首尾的两个指针
typedef struct linkedQueue
{
    ptr_node front;
    ptr_node rear;
}lkdq_node,*lkdq_ptr_node;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

lkdq_ptr_node create_linkedQueue();

//出入队
int enter_linkedQueue(lkdq_ptr_node Q,linkedQueue_data_type newData);
linkedQueue_data_type exit_linkedQueue(lkdq_ptr_node Q);

//判空满
//好像不用判满？
int empty_linkedQueue(lkdq_ptr_node Q);
// int  full_linkedQueue(lkdq_ptr_node Q);

//打印
int show_linkedQueue(lkdq_ptr_node Q);




#endif