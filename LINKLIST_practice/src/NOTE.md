# return value
- ## -1 bad position
  ```cpp
  int len = get_length_linklist(L);
    if(0 > pos || pos > len)
    {
        printf("the position you ask is fatal\n");
        return -1;
    }
    ```

- ## 0 NORMAL
    ```cpp

        return 0;
    ```

- ## -2 
    ```cpp
    int empty_linklist(lklst_ptr_node L)
    {
      if(NULL == L->next)
      {
         printf("L is on the end of the list\n");
         return 0;
     }
     else
     {
         return -2;
     }
    }
    ```
