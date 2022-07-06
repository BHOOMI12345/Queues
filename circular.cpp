#include<iostream>

using namespace std;

class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[n];
        front  = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        if((front == 0 && rear == size-1)||(rear == (front-1)%(size-1)))
        {
            cout<<"Queue is full"<<endl;
        }

        else if(front==-1)
        {
            front = rear = 0;
        }

        else if((rear==size-1) && (front!=0))
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }


    int dequeue()
    {
        if(front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }

        else if(front==rear)
        {
            front = rear = -1;
        }

        else if(front ==size-1)
        {
            front = 0;
        }

        else
        {
            front++;
        }

        int ele = arr[front];
        return ele ;
    }
};
