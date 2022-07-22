#include <iostream>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

class queue
{
    private:
        struct node *front, *rear;

        struct node* create_node(int num)
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            (*temp).data = num;
            (*temp).link = NULL;
            return temp;
        }
    public:
        void Enqueue(int num)
        {
            if(Is_empty())
            {
                front = create_node(num);
                rear = front;
            }
            else
            {
                struct node* temp = create_node(num);
                rear->link = temp;
                rear = temp;
            }
        }
        void Dequeue()
        {
            if(Is_empty())
            {
                std::cout << "Queue is already empty\n";
            }
            else if(front == rear)
            {
                std::cout << "Dequeue - " << front->data << std::endl;
                free(front);
                front = NULL;
                rear = NULL;
            }
            else
            {
                struct node* temp = front;
                front = front->link;

                std::cout << "Dequeue - " << temp->data << std::endl;

                free(temp);
            }
        }
        bool Is_empty()
        {
            if(front == NULL && rear == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void print()
        {
            struct node* temp = front;

            while(temp != NULL)
            {
                std::cout << temp->data << " ";
                temp = temp->link;
            }
            std::cout << std::endl;
            return;
        }
    queue()
    {
        front = NULL;
        rear = NULL;
    }

};

int main()
{
    queue Q;

    Q.Dequeue();
    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.Enqueue(3);
    Q.print();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    return 0;
}