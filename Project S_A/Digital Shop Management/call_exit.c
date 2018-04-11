#include <stdio.h>

#include "S_A.h"
#include "menu_head.h"

void call_exit()
{
    printf("\nPress 'a' to return to admin menu, 'c' to return to customer menu or 'e' to exit\n");
    char action_key = ' ';
    printf("\n");
    while(1)
    {
        action_key = getche();
        if(action_key == 'e')
            user_exit();
        else if(action_key == 'a')
            admin_menu();
        else if(action_key == 'c')
            customer_menu();
        else
            printf("Invalid input\n");
    }
}
