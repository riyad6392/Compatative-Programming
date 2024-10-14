#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Stack{
public:

    int Size;

    Stack()
    {
        Size=0;
    }

    queue<int>q1;
    queue<int>q2;

    void push(int val)
    {
        q2.push(val);
        Size++;

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int>temp=q1;
        q1=q2;
        q2=temp;

    }

    void pop()  // shob thakbe q1 a
    {
        q1.pop();
        Size--;
    }

    int  top()
    {
        return q1.front();
    }

    int size()
    {
        return Size;
    }



};

int main()
{

    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

}
