#include <iostream>
#include <stdlib.h>
#include <queue>

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

void found(bool Found)
{
    if(Found)
    {
        std::cout << "Found\n";
    }
    else
    {
        std::cout << "Not Found\n";
    }
}

int max(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int find_height(struct node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    int height = max(find_height(root->left), find_height(root->right)) + 1;
    return height;
}

void level_trav(struct node* root)
{
    std::queue<struct node*> Q; 

    if(root == NULL)
    {
        return;
    }

    std::cout << "Tree -> ";

    Q.push(root);
    while(!Q.empty())
    {
        std::cout << Q.front()->data << " ";
        if(Q.front()->left != NULL) Q.push(Q.front()->left);
        if(Q.front()->right != NULL) Q.push(Q.front()->right);
        Q.pop();
    }
}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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

    found(search(root, 20));
    found(search(root, 17));
    found(search(root, 18));

    std::cout << "Height = " <<find_height(root) << std::endl;

    level_trav(root);

    std::cout << std::endl << "InOrder -> ";
    inorder(root);
    return 0;
}