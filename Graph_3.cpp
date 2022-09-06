#include <iostream>

struct node
{
    int num;
    int weight;
    struct node* next;
};

void add_edge(struct node** head, int a, int b, int weight = 1)
{
    if(head[a] == NULL)
    {
        head[a] = new struct node;
        head[a]->num = b;
        head[a]->weight = weight;
        head[a]->next = NULL;
    }
    else
    {
        struct node* temp = head[a];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new struct node;
        temp->next->num = b;
        temp->next->weight = weight;
        temp->next->next = NULL;
    }
}

void print_list(struct node** head, int elements)
{
    for(int i = 0; i < elements; i++)
    {
        std::cout << i << " -> ";
        if(head[i] == NULL)
        {
            std::cout << "NULL";
        }
        else
        {
            struct node* temp = head[i];
            while(temp != NULL)
            {
                std::cout << "(" << temp->num << ", " << temp->weight << ") -> ";
                temp = temp->next;
            }
            std::cout << "NULL";
        }
        std::cout << std::endl;
    }
}

/*
struct head
{
    std::string name;
    struct node* head_ptr;
};
*/

int main()
{
    struct node* list[5];

    for(int i = 0; i < 5; i++)
    {
        list[i] = NULL;
    }

    add_edge(list, 0, 4);
    add_edge(list, 0, 1);
    add_edge(list, 1, 4);
    add_edge(list, 1, 3);
    add_edge(list, 1, 2);
    add_edge(list, 1, 1);
    add_edge(list, 3, 4);
    add_edge(list, 3, 2);

    print_list(list, 5);
}