#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "S_A.h"
#include "menu_head.h"

void customer_menu()
{
    system("cls");
    printf("\n\t\t\t\t\t%s", shop_name);
    int check=0,i;
    char move;
    while(1)

    {
        printf("\n\n\n\n");
        for(i=0; i<4; i++)
        {
            if(i==check)
            {
                strupr(str_customer[i]);
                printf("\t\t\t\t%s%s\n",arrow,str_customer[i]);
                strlwr(str_customer[i]);
            }
            else printf("\t\t\t\t   %s\n",str_customer[i]);
        }
        while(1)
        {
            move=getch();
            system("cls");
            printf("\n\t\t\t\t\t%s", shop_name);
            if(move == 13 && check==0)
                customer_item();
            else if(move == 13 && check==1)
                generate_report();
            else if(move == 13 && check==2)
                admin_menu();
            else if(move == 13 && check==3)
                user_exit();
            if(move==72) check--;
            else if(move==80) check++;
            if(check==-1) check=3;
            else if(check==4) check=0;
            printf("\n\n\n\n");
            for(i=0; i<4; i++)
            {
                if(i==check)
                {
                    strupr(str_customer[i]);
                    printf("\t\t\t\t%s%s\n",arrow,str_customer[i]);
                    strlwr(str_customer[i]);
                }
                else printf("\t\t\t\t   %s\n",str_customer[i]);
            }
        }
        printf("%d\n", check);
    }
}
