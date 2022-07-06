#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
    Node * front;
    Node * rear;

    public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int data)
    {
        Node * temp= new Node(10);
        if(rear==NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if(front ==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

        Node * temp= front;
        front = front->next;

        if(front==NULL)
        {
            rear = NULL;
        }

        delete(temp);


    }
};