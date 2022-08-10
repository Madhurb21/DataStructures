#include <iostream>
#include <Stdlib.h>

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

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
        else if(num > root->data)
        {
            root->right = insert(root->right, num);
        }
    }
    return root;
}

void search(struct node* root, int num)
{
    if(root == NULL)
    {
        std::cout << "Not found\n";
        return;
    }
    else
    {
        if(root->data == num)
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
}

void max(struct node* root)
{
    if(root == NULL)
    {
        std::cout << "empty Tree\n";
    }
    else if(root->right == NULL)
    {
        std::cout << root->data << std::endl;
    }
    else
    {
        max(root->right);
    }
}

void min(struct node* root)
{
    if(root == NULL)
    {
        std::cout << "empty Tree\n";
    }
    else if(root->left == NULL)
    {
        std::cout << root->data << std::endl;
    }
    else
    {
        min(root->left);
    }
}

int height(struct node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return (max(height(root->left), height(root->right)) + 1);
    }
}

bool is_greater(struct node* root, int data)
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        if(root->data > data)
        {
            return false;
        }
        else
        {
            return (is_greater(root->left, data) && is_greater(root->right, data));
        }
    }
}

bool is_lesser(struct node* root, int data)
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        if(root->data <= data)
        {
            return false;
        }
        else
        {
            return (is_lesser(root->left, data) && is_lesser(root->right, data));
        }
    }
}

bool is_bst(struct node* root)
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return(is_bst(root->left) && is_bst(root->right) && (is_lesser(root->right, root->data)) && (is_greater(root->left, root->data)));
    }
}

int main()
{
    struct node* root;
    root = NULL;

    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 25);
    root = insert(root, 18);
    root = insert(root, 17);
    root = insert(root, 15);

    search(root, 2);
    search(root, 3);
    search(root, 18);
    search(root, 20);

    max(root);
    min(root);

    std::cout << height(root) << std::endl;

    std::cout << is_bst(root) << std::endl;
}