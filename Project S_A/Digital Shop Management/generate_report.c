#include <stdio.h>
#include <stdlib.h>

#include "S_A.h"
#include "customer.h"
#include "menu_head.h"

void generate_report()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    struct shop *current = head;
    struct customer *current2 = customer_head;
    int total_price, i, num, item_no = 1, net_price = 0;

    if(customer_head == NULL)
    {
        printf("Sorry, there are no items being purchased\n");
        call_exit();
    }
    printf("\t\t\t\tPurchased Item(s)\n\n");
    printf("Item no       "); // 7 spaces after
    printf("         Item Name           "); // 9 spaces b4 and 11 spaces after
    printf("  Amount   "); // 3 spaces after
    printf("   Qty   ");
    printf("   Total Price\n");

    while(current2 != NULL) // will access purchased item
    {
        total_price = current2 -> item_quantity * current2 -> item_price;
        net_price += total_price;

        while(current != NULL) // will find the item being purchased in the main storage list
        {
            if(!(stricmp(current2 -> item, current -> item)))
            {
                current -> item_quantity -= current2 -> item_quantity; // reduce the available quantity of item
                break;
            }
            current = current -> next;
        }


        if(item_no < 99)
            printf(" 0%d       ", item_no);
        else
            printf("  %d       ", item_no);

        printf("%s", current2 -> item);
        for(i = 0; i < 33 - strlen(current2 -> item); i++) // '33' is the number of space between item name and amount
            printf(" ");

        num = atoi(current2 -> item_amount);
        if(!num)
        {
            printf(" N/A");
            for(i = 0; i < 9; i++)
                printf(" ");
        }
        else
        {
            printf(" %s", current2 -> item_amount);
            for(i = 0; i < 12 - strlen(current2 -> item_amount); i++) // '12' is the number of space between item amount and quantity
                printf(" ");
        }

        printf(" %d        ", current2 -> item_quantity);
        printf(" %d ", total_price);
        item_no++;
        printf("\n-----------------------------------------------------------------------------\n");
        current2 = current2 -> next;
    }
    printf("\t\t\t\t\t\t\t\t   %d", net_price);
    customer_head = NULL;
    call_exit(); // after generating report goto menu or exit
}
