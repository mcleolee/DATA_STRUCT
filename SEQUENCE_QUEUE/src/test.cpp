#include "sqqueue.h"
#include <stdio.h>


int main()
{
    sqq_ptr_node Q = create_sqQueue();

    int i;
    for(i  =0; i < 5; i++)
    {
        enter_queue(Q,i+48);
    }
    show_sqqueue(Q);

    printf("\n%d\n", exit_queue(Q));
    printf("%d\n\n", exit_queue(Q));
    show_sqqueue(Q);

}
