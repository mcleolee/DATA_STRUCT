#include "sqstack.h"
#include <stdio.h>
#include <iostream>

	
    
sqstk_ptr_node create_sequence_stack(void)
{
	sqstk_ptr_node S = (sqstk_ptr_node)malloc(sizeof(sqstk_node));
	if(NULL == S)
	{
		printf("memory allocate failed\n");
		return NULL;
	}
	S->top = -1; //不理解
	return S;
}

int empty_sequence_stack(sqstk_ptr_node S)
{
	if(S->top == -1)
	{
		return 0;
	}	
	else
	{
		return -1;
	}
}

int  full_sequence_stack(sqstk_ptr_node S)
{
	if(N-1 == S->top)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

sqstack_data_type pop_sequence_stack(sqstk_ptr_node S)
{
	if(0 == empty_sequence_stack(S))
	{
		printf("the stack is empty\n");
		return -1;
	}
	return S->buf[S->top--];
}

int push_sequence_stack(sqstk_ptr_node S,sqstack_data_type data)
{
	if(0 == full_sequence_stack(S))
	{
		printf("the stack is full\n");
		return -1;
	}

	S->buf[++(S->top)] == data;
	return 0;
}

int show_sequence_stack(sqstk_ptr_node S)
{
	if(0 == empty_sequence_stack(S))
	{
		printf("the stack is empty\n");
		return -1;
	}
	int i = S->top;
	while(i)
	{
		printf("%c",S->buf[i--]);
	}
	printf("\n");
	return 0;
}
