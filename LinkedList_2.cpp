#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* head;

void print_list()
{
    struct node* temp;
    temp = head;

    while(1)
    {
        if(temp == NULL)
        {
            std::cout << "Empty list\n";
            break;
        }
        else
        {
            std::cout << temp->data << " ";
            if(temp->link == NULL)
            {
                break;
            }
            temp = temp->link;
        }
    }
}

void insert_list(int num, int pos)
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));

    temp1->data = num; //storing data
    temp1->link = NULL;

    if(pos == 1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }
    else
    {
        struct node* temp = head;

        for(int i = 0; i < pos - 2; i++)
        {
            temp = temp->link;
        }

        temp1->link = temp->link;
        temp->link = temp1;
    }
}

void delete_list(int pos)
{
    if(pos == 1)
    {
        struct node* temp;
        temp = head->link;

        free(head);

        head = temp;
    }
    else
    {
        struct node* temp,* temp1;
        temp = head;
        for(int i = 0; i < pos - 2; i++)
        {
            temp = temp->link;
        }

        temp1 = temp->link;

        temp->link = temp->link->link;

        free(temp1);
    }
}

int main()
{
    head = NULL;

    insert_list(2, 1); // 2
    insert_list(3, 2); // 2 3
    insert_list(5, 3); // 2 3 5
    insert_list(4, 1); // 4 2 3 5
    insert_list(6, 3); // 4 2 6 3 5
    delete_list(3); // 4 2 3 5
    delete_list(2); // 4 3 5
    delete_list(3); // 4 3

    print_list();
    return 0;
}