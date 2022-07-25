#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

#define initSize 1024
#define StackIncrement 128

typedef int lkstk_data_type; // turn into char
typedef struct linkedStack
{
    // lkstk_data_type data;
    struct linkedStack *bottom;
    struct linkedStack *top;
    int stack_size;
}lkstk_node,*lkstk_ptr_node;

//++++++++ THIS IS A LINKED STACK ++++++++

int init_stack(lkstk_ptr_node S);

int empty_stack(lkstk_ptr_node S);

int length_stack(lkstk_ptr_node S);

int get_top_stack(lkstk_ptr_node S,lkstk_ptr_node data);

int push_stack(lkstk_ptr_node S,lkstk_data_type data);

int exit_stack(lkstk_ptr_node S,lkstk_data_type *data);

int show_stack(lkstk_ptr_node S);
















#endif