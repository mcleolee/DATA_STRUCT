#include "sqQueue.h"
#include <stdio.h>
#include <stdlib.h>

sqq_ptr_node create_sqQueue()
{
    sqq_ptr_node Q = (sqq_ptr_node)malloc(sizeof(sqq_node));
    if(NULL == Q)
    {
        printf("memory allcate failed\n");
        return NULL;
    }
    Q->rear = 0;
	Q->front = 0;
	
	return Q;
}

//入队&出队
int enter_queue(sqq_ptr_node Q,sqqueue_data_type data)
{
    if(0 == full_sqqueue(Q))
    {
        printf("Q is full\n");
        return -1;
    }

    Q->arrData[Q->rear] = data;
	Q->rear = (Q->rear+1)%N;
	
	return 0;
}
sqqueue_data_type exit_queue(sqq_ptr_node Q)
{
    if(0 == empty_sqqueue(Q))
    {
        printf("Q is empty\n");
        return -1;
    }

    sqqueue_data_type data = Q->arrData[Q->front];
    Q->front = (Q->front+1)%N;

    return data;
}

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
    if((Q->rear + 1)%N == Q->front)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


int show_sqqueue(sqq_ptr_node Q)
{
    if(0 == empty_sqqueue(Q))
    {
        printf("Q is empty\n");
        return -1;
    }
    int i;
	for(i = Q->front; i != Q->rear; i=(i+1)%N)
	{
		printf("buf[%d]=%d\n", i, Q->arrData[i]);
	}
	printf("\n");
	
	return 0;
}
