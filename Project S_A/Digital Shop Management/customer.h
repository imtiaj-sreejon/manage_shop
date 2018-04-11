#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

struct customer
{
    char item[100];
    int item_price;
    char item_amount[10];
    int item_quantity;
    struct customer *next;
}*customer_head, *required_item_ptr;

char item_name[40], amount[10] ;
int quantity, cnt;

#endif // CUSTOMER_H_INCLUDED
