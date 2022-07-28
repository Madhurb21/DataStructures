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
    struct node* temp = (struct node*)malloc(sizeof(node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert_rec(struct node* root, int num)
{
    if(root == NULL)
    {
        root = create_node(num);
    }
    else if(num <= root->data)
    {
        root->left = insert_rec(root->left, num);
    }
    else
    {
        root->right = insert_rec(root->right, num);
    }
    return root;
}

struct node* insert_itr(struct node* root, int num)
{
    if(root == NULL)
    {
        root = create_node(num);
    }
    else
    {
        struct node* temp = create_node(num);
        struct node* temp1 = root;
        struct node* temp2;

        while(temp1 != NULL)
        {
            temp2 = temp1;
            if(num <= temp1->data)
            {
                temp1 = temp1->left;
            }
            else
            {
                temp1 = temp1->right;
            }
        }
        if(num <= temp2->data)
        {
           temp2->left = temp;
        }
        else
        {
            temp2->right = temp;
        }
    }
    return root;
}

bool search_rec(struct node* root, int num)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == num)
    {
        return true;
    }
    else if(root->data > num)
    {
        return search_rec(root->left, num);
    }
    else
    {
        return search_rec(root->right, num);
    }
}

bool search_itr(struct node* root, int num)
{
    if(root == NULL)
    {
        return false;
    }
    else
    {
        struct node* temp = root;

        while(1)
        {
            if(temp->data == num)
            {
                return true;
            }
            else
            {
                if(num < temp->data)
                {
                    if(temp->left == NULL)
                    {
                        return false;
                    }
                    temp = temp->left;
                }
                else
                {
                    if(temp->right == NULL)
                    {
                        return false;
                    }
                    temp = temp->right;
                }
            }
        }
    }
}

void found(bool search)
{
    if(search)
    {
        std::cout << "Found\n";
    }
    else
    {
        std::cout << "Not Found\n";
    }
}

int find_max(struct node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        if(root->right == NULL)
        {
            return root->data;
        }
        else
        {
            return find_max(root->right);
        }
    }
}

int find_min(struct node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        if(root->left == NULL)
        {
            return root->data;
        }
        else
        {
            return find_min(root->left);
        }
    }
}

int main()
{
    struct node* root = NULL;

    root = insert_itr(root, 15);
    root = insert_itr(root, 10);
    root = insert_itr(root, 20);
    root = insert_itr(root, 8);
    root = insert_itr(root, 12);
    root = insert_itr(root, 17);
    root = insert_itr(root, 25);

    found(search_itr(root, 20));
    found(search_itr(root, 17));
    found(search_itr(root, 18));

    int max = find_max(root);
    int min = find_min(root);

    std::cout << "Max = " << max << std::endl;
    std::cout << "Min = " << min << std::endl;
    return 0;
}