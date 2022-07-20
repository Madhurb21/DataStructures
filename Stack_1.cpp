#include <iostream>

int stack_array[101];
int top = -1;

void push(int num)
{
    if(top == 100)
    {
        std::cout << "Stack is full\n";
        return;
    }
    top += 1;
    stack_array[top] = num;
}
void pop()
{
    if(top == -1)
    {
        std::cout << "Stack is empty\n";
        return;
    }
    top -= 1;
}
int topElement()
{
    return stack_array[top];
}
bool empty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    bool isEmpty = empty();
    int element;

    pop();
    push(5);
    push(6);
    push(3);

    element = topElement();

    push(2);
    pop();

    for(int i = 0; i <= top; i++)
    {
        std::cout << stack_array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << isEmpty << " " << element << " ";
    return 0;
}