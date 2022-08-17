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

struct node* find_node(struct node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == data)
    {
        return root;
    }
    else if(root->data >= data)
    {
        return find_node(root->left, data);
    }
    else
    {
        return find_node(root->right, data);
    }
}

struct node* find_min(struct node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->left != NULL)
        {
            return find_min(root->left);
        }
        else
        {
            return root;
        }
    }
}

struct node* find_max(struct node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->right == NULL)
    {
        return root;
    }
    else
    {
        return find_max(root->right);
    }
}

struct node* successor(struct node* root, int data)
{
    if(root == NULL)
    {
        return NULL;    
    }
    else
    {
        struct node* current = find_node(root, data);
        if(current->right != NULL)
        {
            return find_min(current->right);
        }
        else
        {
            struct node* temp = NULL;
            struct node* ancestor = root;

            while(ancestor != current)
            {
                if(current->data <= ancestor->data)
                {
                    temp = ancestor;
                    ancestor = ancestor->left;
                }
                else
                {
                    ancestor = ancestor->right;
                }
            }
            return temp;
        }
    }
}

struct node* predecessor(struct node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        struct node* current = find_node(root, data);
        if(current->left != NULL)
        {
            return find_max(current->left);
        }
        else
        {
            struct node* temp = NULL;
            struct node* ancestor = root;

            while(ancestor != current)
            {
                if(ancestor->data < data)
                {
                    temp = ancestor;
                    ancestor = ancestor->right;
                }
                else
                {
                    ancestor = ancestor->left;
                }
            }
            return temp;
        }
    }
}

int main()
{
    struct node* root;
    root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 10);
    root = Insert(root, 12);
    root = Insert(root, 36);
    root = Insert(root, 8);
    root = Insert(root, 17);

    std::cout << (successor(root, 10))->data << std::endl;
    std::cout << (successor(root, 8))->data << std::endl;

    std::cout << (predecessor(root, 17))->data << std::endl;
    std::cout << (predecessor(root, 12))->data << std::endl;
}