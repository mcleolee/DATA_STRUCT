#ifndef _SQSTACK_H
#define _SQSTACK_H

#define N 1024

typedef char sqstack_data_t;
typedef struct sqstack
{       
    sqstack_data_t data;
    struct sqstack *pos;
}sqstk_node,*sqstk_ptr_node;

sqstk_ptr_node create_sequence_stack(void);


#endif