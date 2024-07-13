//https://aaman007.wordpress.com/2018/05/24/trie-problems/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// root node
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

// insert
void insert(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

// searching
bool search(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{

    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        //char str[50];
        string str;
        cin>>str;
        int ln=str.size();
        insert(str, ln);
    }
    cout<<"ENTER NUMBER OF QUERY"<<endl;
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        //char str[50];
        string str;
        cin>>str;
         int ln=str.size();
        if (search(str, ln))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root);
    return 0;
}
