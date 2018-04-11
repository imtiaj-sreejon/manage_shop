#include <stdio.h>
#include <stdlib.h>

#include "S_A.h"
#include "menu_head.h"

void search_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    char item_to_search[40];
    struct shop *current = head, *p[10];
    int flag = 0, i, num, item_no = 0, required_item_no, index = 0, j;
    printf("Enter item to search: ");
    gets(item_to_search);

    while(current != NULL) // will check if more than 1 item with same name is present(might occur if different amounts of item of same name are there)
    {
        if(!(stricmp(current -> item, item_to_search)) )// if required item name is available
        {
            flag = 1;
            p[index++] = current;
        }
        current = current -> next;
    }
    p[index] = NULL;// marking the end of array

    if(!flag)
    {
        printf("Sorry, '%s' is not in store\n", item_to_search);
        call_exit();
    }

    /*
        block to show items of given name
    */
    printf("Item no       "); // 7 spaces after
    printf("         Item Name           "); // 9 spaces b4 and 11 spaces after
    printf("  Amount   "); // 3 spaces after
    printf("   Qty   ");
    printf("   Unit Price\n");

    for(j = 0, item_no = 0; p[j]; item_no++, j++)
    {
        printf("  %d       ", item_no + 1);
        printf("%s", p[item_no] -> item);
        for(i = 0; i < 33 - strlen(p[item_no] -> item); i++) // '33' is the number of space between item name and amount
            printf(" ");

        num = atoi(p[item_no] -> item_amount);
        if(!num)
        {
            printf(" N/A");
            for(i = 0; i < 9; i++)
                printf(" ");
        }
        else
        {
            printf(" %s", p[item_no] -> item_amount);
            for(i = 0; i < 12 - strlen(p[item_no] -> item_amount); i++) // '33' is the number of space between item amount and quantity
                printf(" ");
        }

        printf(" %d        ", p[item_no] -> item_quantity);
        printf(" %d ", p[item_no] -> item_price);
        printf("\n-----------------------------------------------------------------------------\n");
    }

    call_exit();
}
