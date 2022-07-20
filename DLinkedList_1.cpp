#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head;

void insert_at_beginning(int num)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = head;
    if(head != NULL)
    {
        head->prev = temp;
    }
    
    head = temp;
} 

void insert_at_end(int num)
{
    if(head == NULL)
    {
        insert_at_beginning(num);
    }
    else
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = num;
        temp->next = NULL;

        struct node* temp1 = head;

        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }  
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void print()
{
    struct node* temp = head;

    if(temp == NULL)
    {
        std::cout << "Empty list\n";
        return;
    }

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void print_reverse()
{
    struct node* temp = head;
    if(temp == NULL)
    {
        std::cout << "Empty list\n";
        return;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        while(temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << "\n";
    }
}

int main()
{
    head = NULL;

    insert_at_beginning(2);
    insert_at_beginning(3);
    insert_at_beginning(5);
    insert_at_end(4);
    insert_at_end(7);
    insert_at_end(9);

    print(); // 5 3 2 4 7 9

    print_reverse(); // 9 7 4 2 3 5

    return 0;
}