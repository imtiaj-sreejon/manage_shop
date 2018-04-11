#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "S_A.h"
#include "customer.h"
#include "menu_head.h"

void customer_item()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    customer_head = NULL;
    purchase_item();
}

void purchase_item()
{
    char decision;
    int count = 0;
    printf("Item name:  ");
    gets(item_name);

    struct shop *current = head, *p[10]; // the pointer array will store addresses of items with same name
    int flag = 0, index = 0, i;
    while(current != NULL) // will check if more than 1 item with same name is present(might occur if different amounts of item of same name are there)
    {
        if(!stricmp(current -> item, item_name)) // if required item name is available
        {
            flag = 1;
            count ++;
            p[index++] = current;
        }
        current = current -> next;
    }
    p[index] = NULL; // marking the end of array

    if(!flag)
    {
        printf("Sorry, item not available :(\n");
        return_to_customer_item();
    }
    else
    {
amount:
        printf("Amount(if N/A, then enter zero): ");
        gets(amount);
        for(i = 0; p[i]; i++)
        {
            if(!(stricmp(amount, p[i] -> item_amount)))
            {
                if(p[i] -> item_quantity <= 0) // if quantity of item is zero or less
                {
                    printf("Sorry, item not available");
                    return_to_customer_item();
                }
                flag = 2; // for flag = 2, program will go to the part of asking quantity
                required_item_ptr = p[i];
                break;
            }
        }
        if(flag == 1) // if item amount not available
        {
            printf("Sorry, required amount not available :(\n");
            printf("Available amount(s): ");
            for(i = 0; p[i]; i++)
                printf("%s ", p[i] -> item_amount);
            printf("\n");

            decision = ' ';
            while(decision != 'y' || decision != 'Y' || decision != 'n' || decision != 'N')
            {
                printf("Want to change order of amount?(y/n):  ");
                decision = getche();
                fflush(stdin);
                printf("\n");
                if(decision == 'y' || decision == 'Y')
                    goto amount;
                else if(decision == 'n' || decision == 'N')
                    break;
                else
                    printf("Invalid input\n");
            }
            return_to_customer_item();
        }
    }

    if(flag == 2)
    {
        flag = 3;
quantity:
        printf("Qty:   ");
        scanf("%d", &quantity);
        if(required_item_ptr -> item_quantity < quantity) // if desired quantity of item is not available
        {
            printf("Sorry, required quantity of item not available :(\n");
            printf("Available quantity: %d\n",required_item_ptr -> item_quantity);
            decision = ' ';
            while(decision != 'y' || decision != 'Y' || decision != 'n' || decision != 'N')
            {
                printf("Want to change order of quantity?(y/n): ");
                decision = getche();
                if(decision == 'y' || decision == 'Y')
                    goto quantity;
                else if(decision == 'n' || decision == 'N')
                    break;
                else
                    printf("Invalid input\n");
            }
        }
        cnt = 1;
        return_to_customer_item();
    }
}

void return_to_customer_item()
{
    char decision = ' ';
    while(decision != 'y' || decision != 'Y' || decision != 'n' || decision != 'N')
    {
        printf("Want to buy anything else?(y/n):  ");
        decision = getche();
        fflush(stdin);
        printf("\n");
        if(decision == 'y' || decision == 'Y')
        {
            if(customer_head == NULL && !cnt)
            {
                create_structure();
                customer_item();
            }

            else if(customer_head == NULL)
                customer_item();
            else
            {
                create_structure();
                purchase_item();
            }
        }

        else if(decision == 'n' || decision == 'N')
        {
            if(head == NULL)
                purchase_item();
            else
            {
                create_structure();
                generate_report();
            }
        }
        else
            printf("Invalid input\n");
    }
}

void create_structure()
{
    struct customer *n2, *current2, *previous2;
    n2 = malloc(sizeof(struct customer));

    strcpy(n2 -> item, item_name);
    strcpy(n2 -> item_amount, amount);
    n2 -> item_quantity = quantity;
    n2 -> item_price = required_item_ptr -> item_price;
    n2 -> next = NULL;

    // add item alphabetically
    if(customer_head == NULL)
    {
        customer_head = n2;
    }
    else
    {
        // checks if new item is before the first item of list
        if(stricmp(n2 -> item, customer_head -> item) < 0 )
        {
            n2 -> next = customer_head;
            customer_head = n2;
        }
        else
        {
            previous2 = customer_head;
            current2 = customer_head -> next;

            while(current2 != NULL)
            {
                // if new item is alphabetically after previous item and before current item
                if(stricmp(n2 -> item, previous2 -> item) > 0 && stricmp(n2-> item, current2 -> item) < 0)
                {
                    n2 -> next = previous2 -> next;
                    previous2 -> next = n2;
                    break;
                }
                // otherwise move forward
                previous2 = current2;
                current2 = current2 -> next;
            }
            // if end of list is reached without adding new item then add new item at the end of list
            if(current2 == NULL)
            {
                previous2 -> next = n2;
            }
        }
    }
    return;
}


