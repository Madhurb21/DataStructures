#include <iostream>
#include <stdlib.h>

struct node //Declaring node structure
{
    int data;
    struct node* link;
};
struct node* head;

void insert_end(int num) //function for inserting new element at end of list
{
    struct node* temp;
    temp = head;

    struct node* temp1 = (struct node*)malloc(sizeof(struct node)); //Allocating new memory

    (*temp1).data = num;
    (*temp1).link = NULL;

    while((*temp).link != NULL) //Reaching the last element of list
    {
        temp = (*temp).link;
    }

    (*temp).link = temp1; //Linking to new element
}

void print_list() //printing the list
{
    struct node* temp = head;

    while(1) //traversing the list
    {
        std::cout << (*temp).data << std::endl;

        if((*temp).link == NULL)
        {
            break;
        }
        temp = (*temp).link;
    }
}

void insert_begin(int num)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    (*temp).data = num;
    (*temp).link = head;

    head = temp;
}

int main()
{
    head = NULL; //initialize head pointer

    /*
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node)); //Allocating memory for first element, and address is stored in temp

    (*temp).data = 2; 
    (*temp).link = NULL;

    head = temp;
    */
    
    insert_begin(2);
    insert_end(4);
    insert_end(6);
    insert_end(8);
    insert_end(10);
    insert_begin(0);

    print_list();
}