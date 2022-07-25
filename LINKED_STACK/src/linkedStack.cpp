#include <stdio.h>
#include "linkedStack.h"
#include <stdlib.h>

int init_stack(lkstk_ptr_node S)
{
    S->bottom = (lkstk_ptr_node)malloc(sizeof(lkstk_node));
    if(NULL == S->bottom)
    {
        printf("memory allocate failed\n");
        return NULL;
    }

    S->top = S->bottom;
    S->stack_size = initSize;

    return 1;
}

int empty_stack(lkstk_ptr_node S)
{
    // 栈顶指针与栈底指针重合 ————> 为空
    return S->bottom == S->top;
}

int length_stack(lkstk_ptr_node S)
{
    if(S->top == S->bottom)
    {
        return 0;
    }
    return (int)(S->top - S->bottom);
}

int get_top_stack(lkstk_ptr_node S,lkstk_ptr_node eData)
// error: lkstk_data_type *data
{
    if (S->top == S->bottom) {
        return 0;
    } 
    *eData = *(S->top - 1);

    return 1;
}

int push_stack(lkstk_ptr_node S,lkstk_node eData)
{
    *(S->top++) = eData; // 先赋值，后栈顶指针上移
    return 1;
}

int exit_stack(lkstk_ptr_node S,lkstk_ptr_node *eData)
{
    if (S->bottom == S->top) {
        return 0;
    }
    *eData = --S->top; // 栈顶指针先下移，后赋值
    return 1;
}

int show_stack(lkstk_ptr_node S)
{
    lkstk_ptr_node p;

    if (S->top == S->bottom) {
        printf("Stack is NULL.\n");
        return 0;
    }
    p = S->top;
    // 由栈顶依次向下遍历
    while (p > S->bottom) {
        p--;
        printf("%d ", *p);
    }
    printf("\n");
    return 1;
}