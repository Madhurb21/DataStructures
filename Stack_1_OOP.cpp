#include <iostream>
#include <stdlib.h>

class stack
{
    private:
        int max_size;
        int* stack_array;
        int top;

        void create_stack(int Max_size)
        {
            max_size = Max_size;
            stack_array = (int*)malloc(sizeof(int) * max_size); //Creating an empty Stack

            return;
        }

    public:
        void push(int num)
        {
            if(top == max_size - 1)
            {
                std::cout << "Overflow" << std::endl;
                return;
            }
            else
            {
                top += 1;
                stack_array[top] = num;
            }
        }
        void pop()
        {
            if(top == -1)
            {
                std::cout << "Already Empty\n";
                return;
            }
            else
            {
                top -= 1;
            }
        }
        void print()
        {
            for(int i = 0; i <= top; i++)
            {
                std::cout << stack_array[i] << " ";
            }
            std::cout << std::endl;
        }
        int top_num()
        {
            return stack_array[top];
        }
        int* pointer()
        {
            return stack_array;
        }
    stack(int Max_size)
    {
        create_stack(Max_size);
        top = -1;
    }
    stack()
    {
        create_stack(20);
        top = -1;
    }
};

int main()
{
    stack S;

    S.push(5);
    S.push(6);
    S.push(7);

    S.print();

    S.pop();
    
    std::cout << S.top_num() << std::endl;

    S.print();

    S.pop();
    S.pop();
    S.pop();

    return 0;
}