#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sizeof lklst_node is%d\n",sizeof(lklst_node));//16

    lklst_ptr_node H = create_linklist();
    puts("---------------insert 0 1 2 3 4--------");
    for(int i=0;i<5;i++)
    {
        insert_linklist(H,i,i+48);
    }

    show_linklist(H);
    puts("---------------delete pos = 2--------");
    delete_linklist(H,2);
    show_linklist(H);

    puts("---------------change data= 3 new='A'--------");
    change_linklist(H,'3','A');
    show_linklist(H);

    // puts("---------------clean----------");
    // clean_linklist(H);

    // puts("---------------destory----------");
    // destory_linklist(&H);
    // printf("%p",H);
}