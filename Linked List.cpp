#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

void Display();
void Delete();
void Insert();

struct Node{
    string Nama;
    string Gender;
    long long int NIM;
    int Nilai;
    struct Node *next;
};
Node *Current, *First=NULL, *Last=NULL;

//fungsi membuat dan memasukan simpul
void Insert()
{
    Current = new Node;
    cout<<"Masukan Nama : ";cin>>Current->Nama;
    cout<<"Masukan Gender : ";cin>>Current->Gender;
    cout<<"Masukan NIM : ";cin>>Current->NIM;
    cout<<"Masukan Nilai : ";cin>>Current->Nilai;
    Current->next=NULL;
    if (First == NULL)
    {
        First = Last = Current;
    }
    else
    {
       Last->next = Current;
       Last = Current;
    }
    Last->next= NULL;
}

void DeletePos()
{
    int pos;
    cout<<"Masukan posisi : ";cin>>pos;

    Node *temp = First;

    if(pos == 1)
    {
        First = temp->next;
        delete temp;
    }

    for(int i = 1 ; temp != NULL && i<pos-1; i++)
    {
        temp = temp->next;
    }

    if( temp == NULL || temp->next == NULL)
    return;

    Current = temp->next->next;

    delete temp->next;
    temp->next = Current;
}

void delete_mid()
{
    int count = 0;
    Node *temp = First;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    count = count/2;

    temp = First;
    
    if ((count == 0 || count == 1) && temp->next->next == NULL)
    return;

    for (int i = 0; temp != NULL && i < count-1; i++)
    {
        temp = temp->next;
    }
    
    Current = temp->next->next;
    delete temp->next;
    temp->next = Current;
}

//fungsi menghapus linked list
void Delete()
{
    if (First==NULL)
        cout<<"Kosong";
    else if(First == Last)
    {
         First = Last = NULL;
         delete Current;
    }
    else if(First != Last)
    {
        Node *Temp = First;
        while(Temp->next!=Last)
        {
            Temp=Temp->next;
        }
        Current = Last;
        Last = Temp;
        delete Current;
        Last->next=NULL;
    }
}

//fungsi menampilkan linked list
void Display()
{
    if(First == NULL)
    cout<<"Kosong";
    else
    {
        Current = First;
        while (Current != NULL)
        {
            cout<<"Nama : "<<Current->Nama<<endl;
            cout<<"Gender : "<<Current->Gender<<endl;
            cout<<"NIM : "<<Current->NIM<<endl;
            cout<<"Nilai : "<<Current->Nilai<<endl<<endl;
            Current = Current->next;
        }        
    }
}

main()
{
    int Choice;
    //Tampilan Menu
    menu:
    system("cls"); 
    cout<<"LIN. SINGLY LINKED LIST "<<endl;
    cout<<"========================"<<endl;
    cout<<"1. INSERT DATA"<<endl;
    cout<<"2. DELETE DATA"<<endl;
    cout<<"3. DELETE POS"<<endl;
    cout<<"4. DISPLAY DATA"<<endl;
    cout<<"5. EXIT"<<endl;
    cout<<"Enter your choice : ";cin>>Choice;
    switch (Choice)
    {
    case 1:
        system("cls");
        Insert();
        getch();
        goto menu;
    case 2:
    	system("cls");
    	Delete();
    	getch();
    	goto menu;
    case 3:
    	system("cls");
    	DeletePos();
    	getch();
    	goto menu; 
    case 4:
    	system("cls");
    	Display();
    	getch();
    	goto menu;
    default:
        break;
    }
}