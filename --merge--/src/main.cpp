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
        system("cls");
        printf("Inserting new datas into the linked list\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("1. Insert from the start of the linked list.\n");
        printf("2. Insert to a position you want. \n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

        scanf("%d",&input_menu_insert_linkedlist);
        printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        switch (input_menu_insert_linkedlist)
        {
        // Insert from the start of the linked list.
        case 1:
        {
            printf("This is a test,inserting 0 1 2 3 4\n");
            printf("Only input numbers, \nif you enter 5, you'llget 0 1 2 3 4\n");
            printf("\nInput the number\n");

            scanf("%d", &ISTnum);

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

        // Insert to a position you want.
        case 2:
        {
            int pos_menu_linkedList = 0;
            linkedList_data_type ISTdata;

            printf("Inserting to a position you want. \n");
            printf("Input a string will get an error\n");
            printf("(lkdlst_ptr_node LL,int pos, linkedList_data_type ISTdata)\n");
            printf("2 parameters\n1. position\n2. data\n\n");
            printf("Enter position\n");
            scanf("%d",&pos_menu_linkedList);
            printf("Enter data\n");
            scanf("%s",&ISTdata);

            insert_linkedList(H, pos_menu_linkedList, ISTdata);
            printf("\nThe linked list is \n\t");
            print_linkedList(H);
            pauseAndClear();
        }
            break;
        
        default:
        printf("Wrong selection\n");
            break;
        }

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
    system("cls");
    // lkdlst_ptr_node H;
    menu_linkedList();
    return 0;
}