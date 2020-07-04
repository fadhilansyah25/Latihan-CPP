#include<iostream>
#include<string.h>
using namespace std;
// pembuatan simpul 
struct Node
{
    string Name;
    int Queue_Number;
    struct Node *next;
};

// fungsi menambah antrian
void tambah_antrian(Node **tail, int nomer_antrian, string nama)
{
    Node *baru = new Node(), *bantu = new Node();
    baru->Name = nama;
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

// fungsi utama
main()
{
    int pilihan, nomer_antrian = 1;
    string nama;
    Node *tail; 

    menu:
    system("CLS");
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
        system("CLS");
        cout<<"Masukan nama : ";cin>>nama;
        nomer_antrian++;
        tambah_antrian(&tail, nomer_antrian, nama);
        goto menu;
        break;
    default:
        break;
    }
}