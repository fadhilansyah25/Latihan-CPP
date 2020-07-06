#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref)
{
    Node *new_node = new Node();
    //cout<<new_node<<endl;
    cout<<"Enter the data : ";cin>>new_node->data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pushAfter(Node **head_ref)
{
    Node *new_node = new Node();
    cout<<"Enter the data : ";cin>>new_node->data;
    new_node->next = NULL;
    Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;   
}

void middle(Node *prev)
{
    if (prev == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
    Node* new_node = new Node();
    cout<<"Enter the data : ";cin>>new_node->data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void Del_key(Node** head_ref)
{
    int key;
    cout<<"Enter the data wants to be deleted: ";cin>>key;
    Node *temp = *head_ref;
    Node *prev;

    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void print(Node *n)
{
    int count = 0;
    cout<<n<<"<-";
    while(n != NULL)
    {
        cout<<"|"<<n->data<<"|";
        cout<<n->next<<"|<-";
        n = n->next;
        count++;
    }
    cout<<endl;
    count = count/2;
    cout<<count<<endl;
}

int main()
{
    Node *head = NULL;
    push(&head);
    pushAfter(&head);
    pushAfter(&head);
    pushAfter(&head);
    pushAfter(&head);
    pushAfter(&head);
    middle(head->next);
    print(head);
    cout<<endl;
    Del_key(&head);
    cout<<endl;
    print(head);
}

