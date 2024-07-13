#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
    int data;
    struct Node* next;

};

void push(struct Node** head_ref,int new_data)
{


    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    // put in the data
    new_node->data=new_data;

    // link old to new
    new_node->next=(*head_ref);
    (*head_ref)=new_node;


}

void printList(struct Node *ptr)
{

    while(ptr!=NULL)
    {
        cout<<"-->"<<ptr->data;
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr=head;
    struct Node *fast_ptr=head;

    if(head!=NULL)
    {
        while(fast_ptr !=NULL && fast_ptr->next!= NULL)
        {
            fast_ptr=fast_ptr->next->next;
            slow_ptr=slow_ptr->next;

        }
        cout<<"The mid is "<<slow_ptr->data <<endl;


    }

}


int main()
{
    struct Node* head=NULL;
    for(int i=1;i<=5;i++)
    {
        push(&head,i);
        printList(head);
        printMiddle(head);
    }


}


