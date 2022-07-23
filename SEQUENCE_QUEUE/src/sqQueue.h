#ifndef _SQQUEUE_H
#define _SQQUEUE_H

typedef char sqq_data_t;
typedef struct sqQueue
{
    sqq_data_t data;
    struct sqQueue *next;
}sqq_node,*sqq_ptr_node;







#endif