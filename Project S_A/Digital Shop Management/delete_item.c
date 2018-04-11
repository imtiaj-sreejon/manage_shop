#include <stdio.h>
#include <stdlib.h>

#include "S_A.h"
#include "menu_head.h"

void delete_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    struct shop *current = head, *previous = NULL, *required_item_ptr = NULL , *p[10];
    char item_to_delete[50], decision, wait_key;
    int flag = 0, item_no, required_item_no, index = 0, i, num, j;

    printf("Enter item to delete:    ");
    gets(item_to_delete);

    while(current != NULL) // will check if more than 1 item with same name is present(might occur if different amounts of item of same name are there)
    {
        if(!(stricmp(current -> item, item_to_delete)) )// if required item name is available
        {
            flag = 1;
            p[index++] = current;
        }
        current = current -> next;
    }
    p[index] = NULL;// marking the end of array

    if(!flag)
    {
        printf("Sorry, '%s' is not in store\n", item_to_delete);
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

        printf(" %d        ", p[item_no] -> item_quantity);
        printf(" %d ", p[item_no] -> item_price);
        printf("\n-----------------------------------------------------------------------------\n");
    }

    printf("Enter item no of required item to delete it from available storage list: ");
    scanf("%d", &required_item_no);
    required_item_ptr = p[required_item_no - 1];


    decision = ' ';
    while(decision != 'y' || decision != 'Y' || decision != 'n' || decision != 'N')
    {
        printf("\nAre you sure to delete this item?(y/n):  ");
        decision = getche();
        if(decision == 'y' || decision == 'Y')
        {
            if(required_item_ptr == head) // if item to be deleted is the first element
            {
                head = head -> next;
                free(required_item_ptr);
                printf("\nThe item has been deleted successfully\n");
                wait_key = getche();
                break;
            }
            else
            {
                current = head;
                while(current != required_item_ptr) // loop to find the item before the current item to be deleted
                {
                    previous = current;
                    current = current -> next;
                }
                previous -> next = current -> next;
                free(required_item_ptr);
                printf("\nThe item has been deleted successfully\n");
                wait_key = getche();
                break;
            }
        }
        else if(decision == 'n' || decision == 'N')
        {
            printf("\n");
            break;
        }
        else
            printf("Invalid input\n");
    }

    call_exit();
}
