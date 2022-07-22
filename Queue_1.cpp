#include <iostream>
#include <stdlib.h>

class queue
{
    private:
        int queue_size;
        int front, rear;
        int* array;

        void create_array()
        {
            array = (int*)malloc(queue_size * sizeof(int));
        }
    public:
        void Enqueue(int num)
        {
            if(Is_empty())
            {
                front = 0;
                rear = 0;
            }
            else if(Is_full())
            {
                std::cout << "The queue is full\n";
                return;
            }
            else
            {
                rear = ((rear + 1) % queue_size);
            }
            array[rear] = num;
            return;
        }
        void Dequeue()
        {
            if(Is_empty())
            {
                std::cout << "Queue is already empty\n";
                return;
            }
            else
            {
                if(front == rear)
                {
                    int temp = array[front];
                    std::cout << temp << std::endl;
                    front = -1;
                    rear = -1;
                    return;
                }
                int temp = array[front];
                front = ((front + 1) % queue_size);
                std::cout << temp << std::endl;
                return;
            }
        }
        bool Is_empty()
        {
            if(front == -1 && rear == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool Is_full()
        {
            if(((rear + 1) % queue_size ) == front)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void Print()
        {
            for(int i = front; i <= rear; i++)
            {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }

    queue()
    {
        queue_size = 10;
        front = -1;
        rear = -1;
        create_array();
    }
    queue(int size)
    {
        queue_size = size;
        front = -1;
        rear = -1;
        create_array();
    }

};

int main()
{
    queue Q = queue(2);

    Q.Dequeue();

    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.Enqueue(6);

    Q.Dequeue();
    Q.Print();
}