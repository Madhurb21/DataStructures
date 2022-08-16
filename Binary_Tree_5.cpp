#include <iostream>
#include <Stdlib.h>
#include <queue>

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

void level_trav(struct node* root)
{
    std::queue<struct node*> Q;

    if(root == NULL)
    {
        std::cout << "Empty tree\n";
    }
    else
    {
        Q.push(root);

        while(!Q.empty())
        {
            if(Q.front()->left != NULL)
            {
                Q.push(Q.front()->left);
            }
            if(Q.front()->right != NULL)
            {
                Q.push(Q.front()->right);
            }
            std::cout << Q.front()->data << " ";
            Q.pop();
        }
    }
}

void in_order(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        in_order(root->left);
        std::cout << root->data << " ";
        in_order(root->right);
    }
}

/*
struct node* find_min(struct node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* delete_node(struct node* root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    else
    {
        if(data < root->data)
        {
            root->left = delete_node(root->left, data);
        }
        else if(data > root->data)
        {
            root->right = delete_node(root->right, data);
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                root = NULL;
            }
            else if(root->left == NULL)
            {
                struct node* temp = root->right;
                free(root);
                root = temp;
            }
            else if(root->right == NULL)
            {
                struct node* temp = root->left;
                free(root);
                root = temp;
            }
            else
            {
                struct node* temp = find_min(root->right);
                root->data = temp->data;
                root = delete_node(root->right, temp->data);
            }
        }
        return root;
    }
}
*/

struct node* find_min(struct node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* delete_node(struct node* root, int data)
{
    if(root == NULL) return root;
    else if(data < root->data) 
    {
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data) 
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL)
        {
            struct node* temp = root;
            root = temp->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            struct node* temp = root;
            root = temp->left;
            free(temp);
        }
        else
        {
            struct node* temp = find_min(root);
            root->data = temp->data;

            root->right = delete_node(root->right, data);
        }
    }
    return root;
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

    level_trav(root);

    std::cout << std::endl;

    in_order(root);

    std::cout << std::endl;

    root = delete_node(root, 25);

    search(root, 25);
    search(root, 15);
}