#ifndef _GENERAL_H
#define _GENERAL_H

#include <windows.h>

int pauseAndClear()
{
    printf("\n");
    system("pause");
	system("cls");
}


#if 0
//判空
    if(0 == empty_linkedList(LL))
    {
        printf("error:This linked list is empty.\n");
        printf("LL is on the end of the list\n");
        return -1;
    }

// menu
    int input_menu_ = -1;

while(input_menu_)
    {
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t MENU\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("1. Create a new node for this \n");
    printf("2. Insert new datas into the \n");
    printf("3. Delete data from the \n");
    printf("4. Change data from the \n");
    printf("5. Destory the whole \n");
    printf("6. Clean the whole \n");
    printf("7. Reverse the data in the \n");
    printf("8. Sort the linked list from small to large\n");
    printf("9. Print the  now\n");
    printf("\n");
    printf("0. Exit\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");

    scanf("%d",&input_menu_);
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    }

    switch (input_menu_)
{
case 1:
{
    pauseAndClear();
    break;
}

case 2:
{
    pauseAndClear();
    break;
}

case 3:
{
    pauseAndClear();
    break;
}

case 4:
{
    pauseAndClear();
    break;
}

case 5:
{
    pauseAndClear();
    break;
}

case 6:
{
    pauseAndClear();
    break;
}

case 7:
{
    pauseAndClear();
    break;
}

case 8:
{
    pauseAndClear();
    break;
}

case 9:
{
    pauseAndClear();
    break;
}

case 0:
{
    system("cls");
    printf("\nExit success.\n\n");
    break;
}
   

default:
{
    printf("Wrong selection.\n");
    break;
}
    
}







#endif






#endif