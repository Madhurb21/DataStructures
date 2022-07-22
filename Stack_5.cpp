#include <iostream>
#include <string>
#include <stack>

int evaluate(std::string expression, int len)
{

}

int main()
{
    std::string expression;
    char* str[50];
    int ans;

    std::cout << "Enter an expression - ";
    std::cin >> expression;
    ans = evaluate(expression, expression.length());
}

//Implementation of postfix and infix to postfix is pending