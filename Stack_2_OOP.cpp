#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

class Stack
{
    private:
        struct node* head;

        struct node* create_node(int num)
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = num;
            temp->link = NULL;
            return temp;
        }
    public:
        void push(int num)
        {
            struct node* temp = create_node(num);

            temp->link = head;
            head = temp;
        }
        void pop()
        {
            if(head == NULL)
            {
                std::cout << "Stack Already Empty\n";
            }
            else
            {
                struct node* temp = head;

                head = head->link;
                free(temp);
            }
        }
        int top()
        {
            return head->data;
        }
        void print()
        {
            if(head == NULL)
            {
                std::cout << "Empty List\n";
            }
            else
            {
                struct node* temp = head;

                while(temp != NULL)
                {
                    std::cout << temp->data << " ";
                    temp = temp->link;
                }
                std::cout << std::endl;
            }
        }

    Stack()
    {
        head = NULL;
    }

};

int main()
{

    Stack S;

    S.push(2);
    S.push(3);
    S.push(5);
    S.push(7);
    S.print();
    S.pop();

    std::cout << S.top() << std::endl;

    S.print();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    return 0;
}
