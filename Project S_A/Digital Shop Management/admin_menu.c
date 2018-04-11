#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "S_A.h"
#include "menu_head.h"

void admin_menu()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    int check=0,i;
    char move;
    while(1)
    {
        printf("\n\n\n\n");
        for(i=0; i<7; i++)
        {
            if(i==check)
            {
                strupr(str_admin[i]);
                printf("\t\t\t%s%s\n",arrow,str_admin[i]);
                strlwr(str_admin[i]);
            }
            else printf("\t\t\t   %s\n",str_admin[i]);
        }
        while(1)
        {
            move=getch();
            system("cls");
            printf("\n\t\t\t\t\t%s", shop_name);
            if(move == 13 && check==0) show_item();
            else if(move == 13 && check==1) search_item();
            else if(move == 13 && check==2) add_new_item();
            else if(move == 13 && check==3) add_quantity_of_existing_item();
            else if(move == 13 && check==4) delete_item();
            else if(move == 13 && check==5) customer_menu();
            else if(move == 13 && check==6) user_exit();
            if(move==72) check--;
            else if(move==80) check++;
            if(check==-1) check=6;
            else if(check==7) check=0;
            printf("\n\n\n\n");
            for(i=0; i<7; i++)
            {
                if(i==check)
                {
                    strupr(str_admin[i]);
                    printf("\t\t\t%s%s\n",arrow,str_admin[i]);
                    strlwr(str_admin[i]);
                }
                else printf("\t\t\t   %s\n",str_admin[i]);
            }
        }
    }
}
