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
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;

    struct node* temp1 = head;

    if(temp1 == NULL) //empty list
    {
        head = temp;
        temp->link = NULL;
    }
    else
    {
        while(1)
        {
            if(temp1->link == NULL)
            {
                break;
            }
            temp1 = temp1->link;
        }
        temp->link = NULL;
        temp1->link = temp;
    }
}

void print()
{
    struct node* temp;
    temp = head;

    if(temp == NULL)
    {
        std::cout << "Empty List\n";
    }
    else
    {
        while(1)
        {
            std::cout << temp->data << " ";
            if(temp->link == NULL)
            {
                break;
            }
            temp = temp->link;
        }
    }
    std::cout << std::endl;
}

void reverse()
{
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = NULL;

    insert(2);
    insert(3);
    insert(5);
    insert(7);
    insert(11);
    insert(13); // 2 3 5 7 11 13

    print();

    reverse();

    print();
}