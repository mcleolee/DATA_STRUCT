#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "link.h"
#include "general.h"

int linkedList()
{
    lkdlst_ptr_node H;
    int ISTnum = 0;
    int input_menu_linkedlist = -1;

    while(input_menu_linkedlist)
    {
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\tLINKED LIST MENU\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("1. Create a new node for this linked list\n");
    printf("2. Insert new datas into the linked list\n");
    printf("3. Delete data from the linked list\n");
    printf("4. Change data from the linked list\n");
    printf("");
    printf("");
    printf("\n");
    printf("0. Exit\n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");

    scanf("%d",&input_menu_linkedlist);
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

    switch (input_menu_linkedlist)
    {
    case 1:
    {
        printf("Creating a new node for this linked list\n");
        Sleep(600);
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
		Sleep(300);
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

            Sleep(800);
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
    {
        int input_menu_delete_linkedList = 0;
        printf("Deleting data from the linked list\n");
        printf("(lkdlst_ptr_node LL, int pos)\n");
        printf("\nInput the position you want to delete\n");

        scanf("%d",&input_menu_delete_linkedList);

        delete_based_address_linkedList(H,input_menu_delete_linkedList);
        Sleep(400);
        print_linkedList(H);

        pauseAndClear();
        break;
    }
        
    case 4:
    {
        printf("Changing data from the linked list\n");
        printf("Replace the old data with a new data\n");
        printf("(lkdlst_ptr_node LL,linkedList_data_type OLDdata,linkedList_data_type NEWdata)\n");
        
        
        
        
        
        break;
    }
        

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

    case 0: 
        system("cls");
        printf("\nExit success.\n\n");
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
    linkedList();
    return 0;
}