#include <stdio.h>
#include <string.h>

#include "S_A.h"
#include "menu_head.h"

void show_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    struct shop *current;
    current = head;
    int i, num, item_no = 1;
    char action_key;

    if(head == NULL)
    {
        printf("There are no items to show. Press any key to go to menu or 'e' to exit");
        action_key = getche();
        if(action_key == 'e')
            user_exit();
        else
            main();
    }

    printf("Item no       "); // 7 spaces after
    printf("         Item Name           "); // 9 spaces b4 and 11 spaces after
    printf("  Amount   "); // 3 spaces after
    printf("   Qty   ");
    printf("   Unit Price\n");

    while(current != NULL)
    {
        if(item_no < 99)
            printf(" 0%d       ", item_no);
        else
            printf("  %d       ", item_no);

        printf("%s", current -> item);
        for(i = 0; i < 33 - strlen(current -> item); i++) // '33' is the number of space between item name and amount
            printf(" ");

        num = atoi(current -> item_amount);
        if(!num)
        {
            printf(" N/A");
            for(i = 0; i < 9; i++)
                printf(" ");
        }
        else
        {
            printf(" %s", current -> item_amount);
            for(i = 0; i < 12 - strlen(current -> item_amount); i++) // '33' is the number of space between item amount and quantity
                printf(" ");
        }

        printf(" %d        ", current -> item_quantity);
        printf(" %d ", current -> item_price);
        item_no++;
        printf("\n-----------------------------------------------------------------------------\n");
        current = current -> next;
    }

    call_exit();
}
