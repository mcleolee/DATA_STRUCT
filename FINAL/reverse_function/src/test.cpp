#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    lklst_ptr_node H = create_linklist();
    puts("\ninsert 0 1 2 3 4");
    
    for(int i=0;i<5;i++)
    {
        insert_linklist(H,i,i+48);
    }

    show_linklist(H);
    puts("\n");

    puts("reversed order");
    reversed_order_linklist(H);
    show_linklist(H);
    puts("\n");
}
 