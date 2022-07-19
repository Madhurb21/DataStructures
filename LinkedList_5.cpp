#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* head;

void insert(int num)
{
    struct node* temp1 = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = num;

    if(temp1 == NULL) // empty list
    {
        head = temp;
        temp->link = NULL;
    }
    else
    {
        while(temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
        temp->link = NULL;
    }
}

void print()
{
    if(head == NULL)
    {
        std::cout << "Empty List\n";
    }
    else
    {
        struct node* temp1 = head;

        while(temp1 != NULL)
        {
            std::cout << temp1->data;
            temp1 = temp1->link;
        }
        std::cout << std::endl;
    }
}

void reverse(struct node* p)
{
    if(p->link == NULL)
    {
        head = p;
        return;
    }
    reverse(p->link);
    p->link->link = p;
    p->link = NULL;
}

int main()
{
    head = NULL;

    insert(5);
    insert(3);
    insert(6);
    insert(7);

    print(); // 3 5 6 7

    reverse(head);

    print(); // 7 6 5 3
    return 0;
}