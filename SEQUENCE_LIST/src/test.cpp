#include "sqlist.h"
#include <stdio.h>

int main()
{
    sql_pnode L = create_sqlist(); //调用创建的函数

    puts("------------insert 0 1 2 3 4 5------------");
    int i;
    for(i=0;i<6;i++)
    {
        insert_sqlist(L,i,i);
    }
    show_sqlist(L);

    puts("-----------------delete A----------------");
    delete_sqlist(L,'A');
    show_sqlist(L);

    puts("--------------change pos=2 'b'------------");
    change_sqlist(L,'B',2);
    show_sqlist(L);
}