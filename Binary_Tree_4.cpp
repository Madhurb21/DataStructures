#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int num)
{
    if(root == NULL)
    {
        root = create_node(num);
    }
    else
    {
        if(num <= root->data)
        {
            root->left = insert(root->left, num);
        }
        else
        {
            root->right = insert(root->right, num);
        }
    }
    return root;
}

bool search(struct node* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else
    {
        if(data == root->data)
        {
            return true;
        }
        else if(data <= root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }
}

bool is_greater(struct node* root, int data)
{
    if(root == NULL) return true;
    if((root->data > data) && is_greater(root->right, data) && is_greater(root->left,data))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_lesser(struct node* root, int data)
{
    if(root == NULL) return true;
    if((root->data <= data) && is_lesser(root->left, data) && is_lesser(root->left,data))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_bst(struct node* root)
{
    if(root == NULL) return true;
    if(is_bst(root->left) && is_bst(root->right) && is_lesser(root->left, root->data) && is_greater(root->right, root->data))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct node* root;
    root = NULL;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);
    
    if(is_bst(root))
    {
        std::cout << "Yes \n";
    }
    else
    {
        std::cout << "No \n";
    }
    return 0;
}