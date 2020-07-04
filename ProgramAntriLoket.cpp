#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
// pembuatan simpul 
struct Node
{
    string Name;
    int Queue_Number;
    struct Node *next;
};

// fungsi menambah antrian
void tambah_antrian(Node **tail, int nomer_antrian)
{
    Node *baru = new Node(), *bantu = new Node();
    cout<<"Masukan Nama Pengantri : ";cin>>baru->Name;
    baru->Queue_Number = nomer_antrian;

    if (*tail == NULL){
        *tail = baru;
    }else
    {
        bantu = *tail;
        while (bantu->next != NULL)
        bantu = bantu->next;
        bantu->next = baru;
    }
}

// fungsi mencetak sisa antrian
void cetak_antrian(Node **tail)
{
    Node *bantu = new Node();
    if(*tail == NULL){
        cout<<"Antrian Sudah habis ....."<<endl;
    }else
    {
        bantu = *tail;
        while (bantu->next != NULL){
            cout<<"Nama Pengantri : "<<bantu->Name<<endl;
            cout<<"Nomer Antrian : "<<bantu->Queue_Number<<endl;
            cout<<endl;
            bantu = bantu->next;
        }
        cout<<"Nama Pengantri : "<<bantu->Name<<endl;
        cout<<"Nomer Antrian : "<<bantu->Queue_Number<<endl;
    }
    
}

// fungsi utama
main()
{
    int pilihan, nomer_antrian = 1;
    Node *tail = NULL; 

    menu:
    system("cls");
    cout<<"============================================="<<endl;
    cout<<"Program Antri Loket Pembayaran Mahasiswa"<<endl;
    cout<<"============================================="<<endl;
    cout<<"1. Tambah Antrian"<<endl;
    cout<<"2. Panggil Antrian"<<endl;
    cout<<"3. Tampilkan Antrian Tersisa"<<endl;
    cout<<"============================================="<<endl;
    cout<<"masukan pilihan : ";cin>>pilihan;

    switch (pilihan)
    {
    case 1:
        system("cls");
        tambah_antrian(&tail, nomer_antrian);
        nomer_antrian++;
        getch();
        goto menu;
    case 3:
        system("cls");
        cetak_antrian(&tail);
        getch();
        goto menu;
    default:
        break;
    }
}