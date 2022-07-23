#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

typedef char lkstk_data_t;
typedef struct linkedStack
{
    lkstk_data_t data;
    struct linkedStack *next;
}lkstk_node,*lkstk_ptr_node;
















#endif