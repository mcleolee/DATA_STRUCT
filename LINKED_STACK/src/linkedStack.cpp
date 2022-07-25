#include <stdio.h>
#include "linkedStack.h"
#include <stdlib.h>

int init_stack(lkstk_ptr_node S)
{
    S->bottom = (lkstk_ptr_node)malloc(sizeof(lkstk_node));
    
}

int empty_stack(lkstk_ptr_node S);

int length_stack(lkstk_ptr_node S);

int get_top_stack(lkstk_ptr_node S,lkstk_data_type *data);

int push_stack(lkstk_ptr_node S,lkstk_data_type data);

int exit_stack(lkstk_ptr_node S,lkstk_data_type *data);

int show_stack(lkstk_ptr_node S);