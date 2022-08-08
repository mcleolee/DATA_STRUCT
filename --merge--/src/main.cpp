#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "link.h"
#include "general.h"

int menu_linkedList()
{
    lkdlst_ptr_node H;
    int ISTnum = 0;


    while(1)
    {
    int input_menu_linkedlist;
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\tLINKED LIST MENU\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("1. Create a new node for this linked list\n");
    printf("2. Insert new datas into the linked list\n");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");

    scanf("%d",&input_menu_linkedlist);
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

    switch (input_menu_linkedlist)
    {
    case 1:
    {
        printf("Creating a new node for this linked list\n");
        // Sleep(1000);
        H = create_linkedList();
        if(H != NULL)
        {
            printf("The first node of the linked list is created.\n");
            printf("---------------------------------------------\n");
        }
        else
        {
            printf("FATAL:The first node of the linked list is NOT created.\n");
            system("pause");
            break;
        }
        // 好像不能这里打印
		// Sleep(300);
        pauseAndClear();
        break;
    }
    
    case 2:
    {
        int input_menu_insert_linkedlist = 0;
        printf("Inserting new datas into the linked list\n");

        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("1. Insert from the start of the linked list.\n");
        printf("2. Insert to a position you want. \n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

        scanf("%d",&input_menu_insert_linkedlist);
        printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");


        printf("This is a test,inserting 0 1 2 3 4\n");
        printf("Only input numbers, \nif you enter 5, you'llget 0 1 2 3 4\n");
        printf("\nInput the ISTnum\n");

        scanf("%d",&ISTnum);

        Sleep(1200);
        for (int i = 0; i < ISTnum; i++)
        {
            insert_linkedList(H, i, i + 48);
        }
        printf("\nThe linked list is \n\t");
        print_linkedList(H);
        Sleep(300);
        pauseAndClear();

        // 在返回菜单的时候显示 linked list
        // printf("\nThe linked list is \n\t");
        // print_linkedList(H);

        break;
    }
        

    case 3:
        printf("");
        break;

    case 4:
        printf("");
        break;

    case 5:
        printf("");
        break;

    case 6:
        printf("");
        break;
    
    case 7:
        printf("");
        break;

    case 8:
        printf("");
        break;

    case 9:
        printf("");
        break;
    
    default:
        printf("Wrong number\n");
        break;
    }

    }
    
}

int main()
{
    // lkdlst_ptr_node H;
    menu_linkedList();
    return 0;
}