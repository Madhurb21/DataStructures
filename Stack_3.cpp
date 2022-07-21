#include <iostream>
#include <string.h>
#include <stack>

void reverse(char* str, int len)
{
    std::stack<char> S;

    for(int i = 0; i < len; i++)
    {
        S.push(str[i]);
    }
    for(int i = 0; i < len; i++)
    {
        str[i] = S.top();
        S.pop();
    }
}

int main()
{
    char str[50];

    std::cout << "Enter a string - ";
    std::cin >> (str);

    reverse(str, strlen(str));

    puts(str);
}