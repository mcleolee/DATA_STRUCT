#ifndef _SQSTACK_H
#define _SQSTACK_H

#define N 1024

typedef char sqstack_data_type;
typedef struct sqstack
{       
    sqstack_data_type buf[N];
    int top;
}sqstk_node,*sqstk_ptr_node;

sqstk_ptr_node create_sequence_stack(void);

int empty_sequence_stack(sqstk_ptr_node S);
int  full_sequence_stack(sqstk_ptr_node S);

sqstack_data_type pop_sequence_stack(sqstk_ptr_node S);

int push_sequence_stack(sqstk_ptr_node S,sqstack_data_type data);

int show_sequence_stack(sqstk_ptr_node);

#endif