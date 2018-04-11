#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <conio.h>

#include "S_A.h"
#include "menu_head.h"

void add_new_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    struct shop *n, *current = head, *previous;
    int flag = 0, i, num;
    char decision;
    n = malloc(sizeof(struct shop));

    printf("Enter item name to add: ");
    gets(n -> item);

    printf("Enter amount of item (if N/A then enter '0' and put the unit of amount without any space): ");
    gets(n -> item_amount);

    while(current != NULL)
    {
        if(!(stricmp(current -> item, n -> item)) && !(stricmp(current -> item_amount, n -> item_amount)))
        {
            flag = 1;
            printf("Sorry, input item is already available in store\n");
            printf("\n                            Item info                   \n");
            printf("-----------------------------------------------------------------------------\n");
            printf("Item no       "); // 7 spaces after
            printf("         Item Name           "); // 9 spaces b4 and 11 spaces after
            printf("  Amount   "); // 3 spaces after
            printf("   Qty   ");
            printf("   Unit Price\n");

            printf("  01       ");
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
            printf("\n-----------------------------------------------------------------------------\n");
        }
        current = current -> next;
    }

    if(!flag)
    {
        printf("Enter quantity of item: ");
        scanf("%d", &n -> item_quantity);

        printf("Enter price (unit price): ");
        scanf("%d", &n -> item_price);

        n -> next = NULL;

        // add item alphabetically
        if(head == NULL)
            head = n;
        else
        {
            // checks if new item is before the first item of list
            if(stricmp(n -> item, head -> item) < 0 )
            {
                n -> next = head;
                head = n;
            }
            else
            {
                previous = head;
                current = head -> next;

                while(current != NULL)
                {
                    // if new item is alphabetically after previous item and before current item
                    if((stricmp(n -> item, previous -> item) > 0 && stricmp(n -> item, current -> item) < 0) || (!(stricmp(n -> item, previous -> item)) && stricmp(n -> item, current -> item) < 0))
                    {
                        n -> next = previous -> next;
                        previous -> next = n;
                        break;
                    }
                    // otherwise move forward
                    previous = current;
                    current = current -> next;
                }
                // if end of list is reached without adding new item then add new item at the end of list
                if(current == NULL)
                {
                    previous -> next = n;
                }
            }
        }
    }

    char add_another = ' ';
    while(add_another != 'y' || add_another != 'Y' || add_another != 'n' || add_another != 'N')
    {
        printf("Want to add another item?(y/n): ");
        add_another = getche();
        fflush(stdin);
        printf("\n");
        if(add_another == 'y' || add_another == 'Y')
            add_new_item();
        else if(add_another == 'n' || add_another == 'N')
            break;
        else
            printf("Invalid input");
    }

    call_exit();
}
