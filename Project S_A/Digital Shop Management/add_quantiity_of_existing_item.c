#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "S_A.h"
#include "menu_head.h"

void add_quantity_of_existing_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    struct shop *current = head, *p[10], *required_item_ptr;
    char name[40];
    int quantity, index = 0, flag = 0, item_no, required_item_number, i, num, j;
    printf("Enter item name: ");
    gets(name);

    while(current != NULL) // will check if more than 1 item with same name is present(might occur if different amounts of item of same name are there)
    {
        if(!(stricmp(current -> item, name)) )// if required item name is available
        {
            flag = 1;
            p[index++] = current;
        }
        current = current -> next;
    }
    p[index] = NULL;// marking the end of array

    if(!flag)
    {
        printf("Sorry, '%s' is not in store\n", name);
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

    for(item_no = 0, j = 0; p[j]; item_no++, j++)
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

        printf(" %s        ", p[item_no] -> item_quantity);
        printf(" %d ", p[item_no] -> item_price);
        printf("\n-----------------------------------------------------------------------------\n");
    }

    printf("Enter item number of required item to add new quantity: ");
    scanf("%d", &required_item_number);
    required_item_ptr = p[required_item_number - 1];

    while(1)
    {
        printf("Enter quantity of item to add: ");
        scanf("%d", &quantity);
        if(isdigit(quantity)) // if quantity is not a valid number
        {
            printf("Invalid input\n");
            continue;
        }
        required_item_ptr -> item_quantity += quantity;
        printf("Quantity added successfully\n");
        break;
    }

    if(required_item_ptr == NULL)
    {
        printf("%s is not available in store\n", name);
    }
    call_exit();
}
