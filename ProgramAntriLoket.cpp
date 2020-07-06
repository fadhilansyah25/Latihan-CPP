#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;
// pembuatan simpul 
struct Node
{
    string Name;
    int Queue_Number;
    struct Node *next;
};

// Prototype Fungsi
void tambah_antrian(Node **tail, int nomer_antrian);
void panggil_antrian(Node **tail);
void cetak_antrian(Node **tail);
void panggil_Antrian_Acak(Node **tail);

// fungsi menambah antrian
void tambah_antrian(Node **tail, int nomer_antrian)
{
    Node *baru = new Node(), *bantu = new Node();
    cout<<"*jangan input dengan spasi\n";
    cout<<"Masukan Nama Pengantri : ";cin>>baru->Name;
    baru->Queue_Number = nomer_antrian;
    baru->next = NULL;

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

// Fungsi mengeluarkan antrian atau memanggil antrian
void panggil_antrian(Node **tail)
{
    Node *bantu;
    bantu = *tail;
    if(*tail == NULL){
        cout<<"Antrian Sudah habis ....."<<endl;
    }
    else if(bantu->next == NULL){
        cout<<"Antrian dengan Nama : "<<bantu->Name<<"\nDengan nomor Antrian : "<<bantu->Queue_Number<<endl
        <<"\nTelah dipanggil";
        delete bantu;
        *tail = NULL;
    }
    else{
        cout<<"Antrian dengan Nama : "<<bantu->Name<<"\nDengan nomor Antrian : "<<bantu->Queue_Number<<endl
        <<"\nTelah dipanggil";
        *tail = bantu->next;
        delete bantu;
    }
    cetak_antrian(tail);
}

// fungsi mencetak sisa antrian
void cetak_antrian(Node **tail)
{
    Node *bantu;
    if(*tail == NULL){
        cout<<"Antrian Sudah habis ....."<<endl;
    }else
    {
        cout<<"+---------------------------------------+"<<endl;
        cout<<"| Nama pengantri\t| No. Antrian\t|"<<endl;
        cout<<"+---------------------------------------+"<<endl;
        bantu = *tail;
        while (bantu->next != NULL){
            cout<<"| "<<bantu->Name<<"\t\t\t| "<<bantu->Queue_Number<<"\t\t|"<<endl;
            bantu = bantu->next;
        }
        cout<<"| "<<bantu->Name<<"\t\t\t| "<<bantu->Queue_Number<<"\t\t|"<<endl;
        cout<<"+---------------------------------------+"<<endl;
    }
}

// fungsi melongkap antrian
void panggil_Antrian_Acak(Node **tail)
{
    int longkap;
    Node *bantu, *sebelum;
    bantu = *tail;
    cetak_antrian(tail);
    cout<<"Masukan nomer antrian : ";cin>>longkap;

    if(bantu != NULL && bantu->Queue_Number == longkap){
        *tail = bantu->next;
        cout<<"Antrian dengan nama "<<bantu->Name<<" dengan nomer antrian "
        <<bantu->Queue_Number<<" Telah dipanggil\n";
        delete bantu;
    }
    else if (bantu != NULL && bantu->Queue_Number != longkap)
    {
        while (bantu->Queue_Number != longkap)
        {
            sebelum = bantu;
            bantu = bantu->next;
        }
        cout<<"Antrian dengan nama "<<bantu->Name<<" dengan nomer antrian "
        <<bantu->Queue_Number<<" Telah dipanggil\n";
        sebelum->next = bantu->next;
        delete bantu;
    }
}

// fungsi utama
main()
{
    int pilihan, nomer_antrian = 1;
    Node *tail = NULL; 

    // Nama : Muhammad Fadil Ardiansyah
    // NIM : 181011400596
    // Kelas : 04TPLP005

    menu:
    system("cls");
    cout<<"Nama : Muhammad Fadil Ardiansyah\nNIM : 181011400596 \nKelas : 04TPLP005\n";
    cout<<"============================================="<<endl;
    cout<<"Program Otomatis Nomor Antrian Loket Pembayaran Mahasiswa"<<endl;
    cout<<"============================================="<<endl;
    cout<<"1. Tambah Antrian"<<endl;
    cout<<"2. Cetak Tersisa"<<endl;
    cout<<"3. Panggil Antrian Paling Depan"<<endl;
    cout<<"4. Panggil Antrian Secara Random"<<endl;
    cout<<"5. Keluar dari program"<<endl;
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
    case 2:
        system("cls");
        cetak_antrian(&tail);
        getch();
        goto menu;
    case 3:
        system("cls");
        panggil_antrian(&tail);
        getch();
        goto menu;
    case 4:
        system("cls");
        panggil_Antrian_Acak(&tail);
        getch();
        goto menu;
    case 5:
        exit(0);
    default:
        goto menu;
    }
}