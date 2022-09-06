#include <iostream>

void add_edge(int** adj_mat, int a, int b)
{
    adj_mat[a][b] = 1;
}

void add_edge(int** adj_mat, int a, int b, int weight)
{
    adj_mat[a][b] = weight;
}

int main()
{
    int** adj_mat;
    adj_mat = new int*[5];
    for(int i = 0; i < 5; i++)
    {
        adj_mat[i] = new int[5];
        for(int j = 0; j < 5; j++)
        {
            adj_mat[i][j] = 0;
        }
    }

    add_edge(adj_mat, 0, 1, 5);
    add_edge(adj_mat, 0, 4);
    add_edge(adj_mat, 1, 1, 6);
    add_edge(adj_mat, 1, 2);
    add_edge(adj_mat, 1, 3);
    add_edge(adj_mat, 1, 4, 8);
    add_edge(adj_mat, 3, 2, 9);
    add_edge(adj_mat, 3, 4);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cout << adj_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}