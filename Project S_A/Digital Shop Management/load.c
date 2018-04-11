#include <stdio.h>

#include "S_A.h"

void load()
{
    FILE *fp;
    fp = fopen("items_in_store.txt", "rb");

    if(fp == NULL)
    {
        printf("Error reading file\n");
        return;
    }

    int count = 0;
    struct shop *current_read, *current_node;
    while(1)
    {
        current_read = malloc(sizeof(struct shop));
        if(fread(current_read, sizeof(struct shop), 1, fp) != 1)
        {
            if(!count) // if count remains zero at the very first read then there's no item on the list
                printf("Sorry, currently no item is available in the shop :(\n");

            if(feof(fp))
            {
                return;
            }
            return;
        }
        // putting NULL to mark the end of list(current item to be read will be the last node)
        // next item to be read will be put after last node, in 'else' block
        current_read -> next = 0;
        count++;

        if(head == NULL)
        {
            head = current_read;
        }
        else
        {
            current_node = head;
            while(current_node -> next != NULL)
            {
                current_node = current_node -> next;
            }
            current_node -> next = current_read;
        }
    }
}
