#include <stdio.h>
#include <windows.h>
#include <string.h>
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
    printf("5. Destory the whole linked list\n");
    printf("6. Clean the whole linked list\n");
    printf("7. Reverse the data in the linked list\n");
    printf("8. Sort the linked list from small to large\n");
    printf("9. Print the linked list now\n");
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
        Sleep(400);
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
            // printf("\nThe linked list is \n\t");
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
            // printf("(lkdlst_ptr_node LL,int pos, linkedList_data_type ISTdata)\n");
            printf("2 parameters\n1. position\n2. data\n\n");
            printf("Enter position\n");
            scanf("%d",&pos_menu_linkedList);
            printf("Enter data\n");
            scanf("%s",&ISTdata);

            insert_linkedList(H, pos_menu_linkedList, ISTdata);
            // printf("\nThe linked list is \n\t");
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
        // printf("(lkdlst_ptr_node LL, int pos)\n");
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
        linkedList_data_type OLDdata,NEWdata;
        printf("Changing data from the linked list\n");
        printf("Replace the old data with a new data\n");
        // printf("(lkdlst_ptr_node LL,linkedList_data_type OLDdata,linkedList_data_type NEWdata)\n");
        printf("\n2 parameters\n1. old data\n2. new data\n\n");
        printf("Input the old data\n");
        scanf("%s",&OLDdata);
        printf("Input the new data\n");
        scanf("%s",&NEWdata);

        change_linkedList(H,OLDdata,NEWdata);
        // change_linkedList(H,'2','9');
        print_linkedList(H);

        printf("the return value of change_linkedList is %d\n",change_linkedList(H,OLDdata,NEWdata));
        pauseAndClear();
        
        
        break;
    }
        

    case 5:
    {
        // 因为 clean 有问题，所以这个测试都没测试
        printf("Destorying the whole linked list\n");
        destory_linkedList(&H);
        Sleep(400);
        printf("Destory success\n");
        printf("\nThe linked list is \n\t");
        print_linkedList(H);

        pauseAndClear();
        break;
    }
        

    case 6:
    {
        printf("Cleaning the whole linked list\n");
        clean_linkedList(H);
        Sleep(400);
        printf("\nClean success\n");
        Sleep(400);
        // 一打印直接出事
        // int ret = print_linkedList(H);
        // printf("\nThe return value of print_linkedList is %d\n",ret);
        // print_linkedList(H);
        pauseAndClear();
        break;
    }
        
    
    case 7:
    {
        printf("Reversing the data in the linked list\n");
        Sleep(200);
        reversed_order_linkedList(H);
        print_linkedList(H);

        pauseAndClear();
        break;
    }
        

    case 8:
    {
        printf("Sorting the linked list\n");
        Sleep(200);
        sort_linkedList(H);

        print_linkedList(H);
        pauseAndClear();
        break;
    }
        

    case 9:
    {
        Sleep(50);
        print_linkedList(H);
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
        printf("Wrong number\n");
        break;
    }
    }
    
}

int linkedQueue()
{
    lkdq_ptr_node H;
    int input_menu_linkedQueue = -1;

    while (input_menu_linkedQueue)
    {
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("\tLINKED QUEUE MENU\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("1. Create a new node for this linked queue\n");
        printf("2. Enter new datas into the linked queue\n");

        printf("3. Delete data from the \n");
        printf("4. Change data from the \n");
        printf("5. Destory the whole \n");
        printf("6. Clean the whole \n");
        printf("7. Reverse the data in the \n");
        printf("8. Sort the linked list from small to large\n");

        printf("9. Print the linked queue now\n");
        printf("\n");
        printf("0. Exit\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");

        scanf("%d", &input_menu_linkedQueue);
        printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    

    switch (input_menu_linkedQueue)
    {
    case 1:
    {
        printf("Creating a new node for this linked queue\n");
        Sleep(400);
        H = create_linkedQueue();
        if(H != NULL)
        {
            printf("The first node of the linked queue is created.\n");
            printf("---------------------------------------------\n");
        }
        else
        {
            printf("FATAL:The first node of the linked queue is NOT created.\n");
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
        int ISTnum = 0;
        system("cls");
        printf("Enter new datas into the linked queue\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        // Insert from the start of the linked queue.

        // printf("This is a test,enter 0 1 2 3 4\n");
        // for (int i = 0; i < 5; i++)
        // {
        //     enter_linkedQueue(H, i + 48);
        // }

        printf("Enter numbers only, \nif you enter 5, you'llget 0 1 2 3 4\n");
        printf("\nInput the number you want to enter\n");

        scanf("%d", &ISTnum);
        Sleep(600);
        for (int i = 0; i < ISTnum; i++)
        {
            enter_linkedQueue(H, i+48);
        }
        print_linkedQueue(H);
        Sleep(300);
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
        printf("Print the linked queue now\n");
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
    }
}