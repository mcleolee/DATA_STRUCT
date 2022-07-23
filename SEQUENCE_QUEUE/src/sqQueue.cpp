#include "sqQueue.h"
#include <stdio.h>
#include <stdlib.h>

sqqueue_data_type create_sqQueue()
{
    sqq_ptr_node Q = (sqq_ptr_node)malloc(sizeof(sqq_node));
    if()
}

//入队&出队
int enter_queue(sqq_ptr_node Q,sqqueue_data_type data);
sqqueue_data_type exit_queue(sqq_ptr_node Q);

//判空&判满
int empty_sqqueue(sqq_ptr_node Q)
{
    if(Q->rear == Q->front)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int full_sqqueue(sqq_ptr_node Q)
{
    if((Q->rear + 1) == Q->front)
}


int show_sqqueue(sqq_ptr_node Q);
