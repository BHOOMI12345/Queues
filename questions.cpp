#include <iostream>
#include<unordered_map>
#include <stack>
#include <queue>
#include <deque>

struct petrolPump
{
    int petrol;
    int distance;
};

using namespace std;

// Q1 REVERSING QUEUE

queue<int> reversing(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    return q;
}

// Q2 FIND FIRST NEGATIVE NUMBERS OF THE WINDOW SIZE

vector<long long> numbers(long long int A[], long long int N, long long int K)
{
    deque<int> dq;
    vector<long long> ans;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = K; i < N; i++)
    {
        if (!dq.empty() && i - dq.front() >= K) // removal
        {
            dq.pop_front();
        }

        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}


//Q3 REVERSE FIRST K ELEMENTS OF THE QUEUE

queue <int> reverseK(queue<int> q,int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val); 
    }

    return q;
    
}

//Q4 FIND FIRST NON REPEATING CHARACTERS IN THE STEAM

string nonRepeatingChars(string A)
{
    unordered_map<char,int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if(count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
            }
        }

        if(q.empty())
        {
            ans.push_back('#');
        }
        
    }
    return ans;
}


//Q5 CIRCULAR TOUR

int tour(petrolPump p[],int n)
{
    int deficit = 0;
    int start = 0;
    int balance = 0;

    for (int i = 0; i <n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0)
        {
            deficit+= balance;
            balance = 0;
            start = i+1;
        }
    }

    if(balance+deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
    
}

//Q6 K QUEUES IN AN ARRAY

class Kqueue
{
    public:
    int n;
    int k;
    int* front;
    int * rear;
    int *arr;
    int freespot;
    int *next;

    Kqueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i]  = -1;
            rear[i] = -1;
        }
        
        arr = new int[n];
        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;

        freespot = 0;
        
    }

    void enqueue(int data, int qn)
    {
        if(freespot==-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }

        //find index
        int index = freespot;

        //update freespot
        freespot = next[index];
        
        //if single element

        if(front[qn-1]==-1)
        {
            front[qn-1] = index;
        }

        else
        {
            next[rear[qn-1]] = index; 
        }

        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if(front[qn-1]==-1)
        {
            cout<<"Queue is empty"<<endl;
        }

        //find index

        int index = front[qn-1];

        front[qn-1] = next[index];

        //manage free spots

        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};


//  Q7 SUM OF MINIMUM AND MAXIMUM ELEMENTS OF ALL THE SUBARRAYS OF SIZE K

int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && maxi.back()<=arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && mini.back()>=arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
    }

    int ans =0;
    for (int i = k; i < n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        //removal

        while (!maxi.empty() && i - maxi.front() >=k)
        {
            maxi.pop_back();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_back();
        }

        //addition
        
        while (!maxi.empty() && maxi.back()<=arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && mini.back()>=arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        
    }
    
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
    
}