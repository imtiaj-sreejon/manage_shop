#ifndef S_A_H_INCLUDED
#define S_A_H_INCLUDED

struct shop
{
    char item[100];
    int item_price;
    char item_amount[10];
    int item_quantity;
    struct shop *next;
}*head;


void load();
void menu();
void add_new_item();
void add_quantity_of_existing_item();
void user_exit();
void show_item();
void delete_item();
void search_item();
void customer_item();
void call_exit();
void generate_report();

#endif // S_A_H_INCLUDED
