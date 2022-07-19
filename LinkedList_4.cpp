#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* insert(int num, struct node* head)
{
    struct node* temp1 = head;
    struct node* temp = new node;
    temp->data = num;
    
    if(temp1 == NULL) //empty list
    {
        temp1 = temp;
        temp->link = NULL;
        return temp1;
    }
    else
    {
        while(temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
        temp->link = NULL;
        return head;
    }
}

void print(struct node* head)
{
    if(head == NULL)
    {
        std::cout << std::endl;
        return;
    }

    std::cout << head->data << " ";
    print(head->link);
}

void print_reverse(struct node* head)
{
    if(head == NULL)
    {
        std::cout << std::endl;
        return;
    }
    print_reverse(head->link);
    std::cout << head->data << " ";
}

int main()
{
    struct node* head;
    head = NULL;

    head = insert(2, head);
    head = insert(3, head);
    head = insert(5, head);
    //head = insert(7, head);
    //head = insert(11, head); 

    print(head); //2 3 5 7 11 
    print_reverse(head); //11 7 5 3 2 
}