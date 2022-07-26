#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sizeof lklst_node is %d\n",sizeof(lklst_node));//16

    lklst_ptr_node H = create_linklist();
    puts("---------------insert 0 1 2 3 4--------");
    
    for(int i=0;i<9;i++)
    {
        insert_linklist(H,i,i+48);
    }


    show_linklist(H);


    puts("---------------delete pos = 2 & 5--------");
    delete_based_address_linklist(H,2);
    delete_based_address_linklist(H,5);
    show_linklist(H);


}