#include<iostream>

using namespace std;

class DEQueue{
    int size;
    int* arr;
    int front;
    int rear;

    public:
    DEQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int data)
    {
        if((front==0 && rear == size-1)||(rear == (front-1)%(size-1)))   //circular nature
        {
            cout<<"Queue is full"<<endl;
        }

        else if(front== -1)    //Empty
        {
            front = rear = 0;
        }

        else if (front == 0)   //single element
        {
            front = size-1;
        }
        else
        {
            front = front--;   //normal flow
        }

        arr[front] = data;
    }

    void push_rear(int data)
    {
        if((front == 0 && rear == size-1)||(rear == (front-1)%(size-1)))
        {
            cout<<"Queue is full"<<endl;
        }

        else if (front==-1)
        {
            front= rear = 0;
        }

        else if (rear == size-1 && front!=0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    int pop_front()
    {
        int ele;
        ele = arr[front];

        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
        }
         
        else if(front== rear)
        {
            front = rear = -1;
        }

        else if(front== size-1)
        {
            front = 0;
        }

        else
        {
            front++;
        }
        
        return ele;
    }

    int pop_rear()
    {
        int ele;
        ele = arr[rear];
        if(front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }

        else if(front == rear)
        {
            front= rear = -1;
        }

        else if (rear==0)
        {
            rear = size-1;
        }
        else
        {
            rear--;
        }
        return ele;
    }


};
