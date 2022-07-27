#include "linkedQueue.h"
#include <stdio.h>

int main()
{
    lkdq_ptr_node Q = create_linkedQueue();

    for(int i=0;i<5;i++)
    {
        enter_linkedQueue(Q,i+48);
    }
    show_linkedQueue(Q);

    printf("data=%c\n",exit_linkedQueue(Q));
    printf("data=%c\n",exit_linkedQueue(Q));

    show_linkedQueue(Q);
}