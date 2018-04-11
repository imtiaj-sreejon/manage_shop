#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "S_A.h"
#include "menu_head.h"

void main_menu()
{
    system("cls");
    strcpy(shop_name, "IUT CDS\n\t\t\t\t-----------------------\n");
    printf("\n\t\t\t\t\t%s", shop_name);
    strcpy(arrow,"==> ");
    strcpy(str_admin[0],"show item");
    strcpy(str_admin[1],"search item");
    strcpy(str_admin[2],"add new item");
    strcpy(str_admin[3],"add quantity of existing item");
    strcpy(str_admin[4],"delete item");
    strcpy(str_admin[5],"customer menu");
    strcpy(str_admin[6],"exit");
    strcpy(str_customer[0],"customer item");
    strcpy(str_customer[1],"generate report");
    strcpy(str_customer[2],"admin menu");
    strcpy(str_customer[3],"exit");
    strcpy(str_main[0],"admin\n");
    strcpy(str_main[1],"customer\n");
    strcpy(password,"cdscds");
    int check=0,i;
    char move;
    while(1)
    {
        printf("\n\n\n\n");
        for(i=0; i<2; i++)
        {
            if(i==check)
            {
                strupr(str_main[i]);
                printf("\t\t\t\t%s%s\n",arrow,str_main[i]);
                strlwr(str_main[i]);
            }
            else printf("\t\t\t\t   %s\n",str_main[i]);
        }
        while(1)
        {
            move=getch();
            if(move==13)
            {
                system("cls");
                printf("\n\t\t\t\t\t%s", shop_name);
                break;
            }
            system("cls");
            printf("\n\t\t\t\t\t%s", shop_name);
            if(move==72) check--;
            else if(move==80) check++;
            if(check==-1) check=1;
            else if(check==2) check=0;
            printf("\n\n\n\n");
            for(i=0; i<2; i++)
            {
                if(i==check)
                {
                    strupr(str_main[i]);
                    printf("\t\t\t\t%s%s\n",arrow,str_main[i]);
                    strlwr(str_main[i]);
                }
                else printf("\t\t\t\t   %s\n",str_main[i]);
            }
        }
        if(check==0) pass();
        else if(check==1) customer_menu();
    }
}


void pass()
{
    int i=0;
    printf("\n\n\n\n");
    puts("*************Enter your password to continue*************");
    printf("Password: ");
    while(1)
    {
        pass_input[i++]=getch();
        printf("*");
        if(pass_input[i-1]==13) break;
    }
    pass_input[i-1]='\0';
    if(strcmp(pass_input,password)==0)
    {
        system("cls");
        printf("\n\t\t\t\t\t%s", shop_name);
        admin_menu();
    }
    else
    {
        system("cls");
        printf("\n\t\t\t\t\t%s", shop_name);
        puts("\nWrong Password.. Try again\n");
        pass();
    }
}

