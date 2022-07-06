#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 1000001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int element)
    {
        if (rear == size)
        {
            cout<<"Queue is full"<<endl;
        }

        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int dequeue()
    {
        int ele;
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            ele = arr[front];
            front++;
        }
        return ele;
    }

    int front()
    {
        if(front== rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<arr[front]<<endl;
        }
    }
};
