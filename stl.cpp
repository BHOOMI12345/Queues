#include<iostream>

#include<queue>

using namespace std;

int main()
{
    queue<int>  q;
    q.push(10);
    cout<<"front : "<<q.front()<<endl;
    q.push(20);
    cout<<"front : "<<q.front()<<endl;
    q.push(30);
    cout<<"front : "<<q.front()<<endl;

    q.pop();
    cout<<"front : "<<q.front()<<endl;

    if(q.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }

    cout<<q.size()<<endl;
}