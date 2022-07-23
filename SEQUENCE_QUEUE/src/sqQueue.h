#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#define N 1024

typedef char sqq_data_type;
typedef struct sqQueue
{
    sqq_data_type arrData[N];
    sqq_data_type data;
    struct sqQueue *front;
    struct sqQueue *rear;
}sqq_node,*sqq_ptr_node;

sqq_data_type init_sqQueue(sqq_ptr_node L);







#endif