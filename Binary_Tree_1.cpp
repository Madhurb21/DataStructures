#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int num)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* Insert(struct node* root, int num)
{
    if(root == NULL)
    {
        root = create_node(num);
    }
    else if(num <= root->data)
    {
        root->left = Insert(root->left, num);
    }
    else
    {
        root->right = Insert(root->right, num);
    }
    return root;
}

void search(struct node* root, int num)
{
    if(root == NULL)
    {
        std::cout << "Not found\n";
    }
    else if(num == root->data)
    {
        std::cout << "Found\n";
    }
    else if(num < root->data)
    {
        search(root->left, num);
    }
    else
    {
        search(root->right, num);
    }
}

int main()
{
    struct node* root;
    root = NULL;

    search(root, 52);

    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 25);

    search(root, 10);
    search(root, 20);
}