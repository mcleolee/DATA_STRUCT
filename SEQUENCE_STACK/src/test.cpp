#include "sqstack.h"
#include <stdio.h>


int main()
{
	sqstk_ptr_node S = create_sequence_stack();
    for(int i=0;i<5/*压5个数据入栈*/;i++)
    {
        push_sequence_stack(S,i+48);
    }

    show_sequence_stack(S);

    for(int i = 0; i < 2; i++)
	{
		pop_sequence_stack(S);
	}
	show_sequence_stack(S);

}
