#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#define N 1024

typedef char sqqueue_data_type;
typedef struct sqQueue
{
    sqqueue_data_type arrData[N];
    int front;
    int rear;
}sqq_node,*sqq_ptr_node;

sqqueue_data_type create_sqQueue();

//入队&出队
int enter_queue(sqq_ptr_node Q,sqqueue_data_type data);
sqqueue_data_type exit_queue(sqq_ptr_node Q);

//判空&判满
int empty_sqqueue(sqq_ptr_node Q);
int full_sqqueue(sqq_ptr_node Q);

int show_sqqueue(sqq_ptr_node Q);

#endif