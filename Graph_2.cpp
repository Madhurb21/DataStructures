#include <iostream>
#include <vector>

void add_edge(std::vector<int>* adj_list, int a, int b)
{
    adj_list[a].push_back(b);
}

void add_edge_weighted(std::vector<std::pair<int, int>>* adj_list, int a, int b)
{
    adj_list[a].push_back(std::make_pair(b, 1));
}

void add_edge_weighted(std::vector<std::pair<int, int>>* adj_list, int a, int b, int weight)
{
    adj_list[a].push_back(std::make_pair(b, weight));
}

int main()
{
    std::vector<int> adj_list[5];
    std::vector<std::pair<int, int>> adj_list_weigt[5];

    return 0;
}