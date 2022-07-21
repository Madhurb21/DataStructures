#include <iostream>
#include <string.h>
#include <stack>

bool pair(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool check_balanced_para(char* str, int n)
{
    std::stack<char> s;

    for(int i = 0; i < n; i++)
    {
        if((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            s.push(str[i]);
        }
        else if((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
        {
            if((s.empty()) || !pair(s.top(), str[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}

int main()
{
    char str[50];
    std::cout << "Enter an expression - ";
    std::cin >> str;

    bool balanced = check_balanced_para(str, strlen(str));

    if(balanced == true)
    {
        std::cout << "Balanced\n";
    }
    else    
    {
        std::cout << "Unbalanced\n";
    }
}