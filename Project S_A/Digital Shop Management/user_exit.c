#include <stdio.h>
#include <string.h>

#include "S_A.h"

void user_exit()
{
    FILE *fp;
    fp = fopen("items_in_store.txt", "wb");
    if(fp == NULL)
    {
        printf("Error reading file");
        return;
    }

    struct shop *current;
    current = head;
    while(current != NULL)
    {
        if(fwrite(current, sizeof(struct shop), 1, fp) != 1)
        {
            printf("Error writing file");
            exit(1);
        }
        current = current -> next;
    }
    exit(1);
}
