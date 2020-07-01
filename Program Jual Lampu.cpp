#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;

//fungsi Untuk Kop Toko
void kop(){
	cout<<"                PENJUALAN LAMPU AJAIB 'UMT LAMP' "<<endl;
	cout<<"              JL.Cikokol No.21 Telp (021) 98878990 "<<endl;
}

//fungsi Untuk menampilkan garis
void garis(){
	int q;
	for(q=0; q<65; q++)
	{
		cout<<"=";
	}
	cout<<endl;
}

//Deklarasi class Lampu
class Lampu{
	public:
		char kode[2];
     	string merek;
		int watt, jml_beli;
     	long harga, subtotal;
}lamp[50];


int main()
{
   	garis();
		
	int j_pesan, i, total=0;
	string nama;
	char menu;
	
   //Tampilan Input
	kop();
	garis();
	cout<<"Masukan Nama Pemesan : "; cin>>nama;
	cout<<"Masukan Jumlah pesanan : "; cin>>j_pesan;
   garis();
   cout<<endl;
   input:
   system("cls");
	
	for(i=1; i<=j_pesan; i++)
	{
		cout<<"Data pesanan ke-"<<i<<endl;
		cout<<"Masukan Kode Lampu [PL/OL/SL]: ";cin>>lamp[i].kode;
		cout<<"Masukan Watt [10/25]: ";cin>>lamp[i].watt;
      if(strcmp(lamp[i].kode,"PL")==0||strcmp(lamp[i].kode,"pl")==0)
      {
         lamp[i].merek="Phillips Lamp";
         cout<<"Merk Lamp: "<<lamp[i].merek<<endl;
         if(lamp[i].watt==10)
         {
            lamp[i].harga=12000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else if(lamp[i].watt==25)
         {
            lamp[i].harga=20000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else
         {
            cout<<"anda Salah memasukan watt"<<endl;
            getch();
            goto input;
         }

      }
      else if(strcmp(lamp[i].kode,"OL")==0||strcmp(lamp[i].kode,"ol")==0)
      {
         lamp[i].merek="Osram Lamp";
         cout<<"Merk Lamp: "<<lamp[i].merek<<endl;
         if(lamp[i].watt==10)
         {
            lamp[i].harga=14000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else if(lamp[i].watt==25)
         {
            lamp[i].harga=25000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else
         {
            cout<<"anda Salah memasukan watt"<<endl;
            getch();
            goto input;
         }
         

      }
      else if(strcmp(lamp[i].kode,"SL")==0||strcmp(lamp[i].kode,"sl")==0)
      {
         lamp[i].merek="Sinyoku Lamp";
         cout<<"Merk Lamp: "<<lamp[i].merek<<endl;
         if(lamp[i].watt==10)
         {
            lamp[i].harga=16000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else if(lamp[i].watt==25)
         {
            lamp[i].harga=30000;
            cout<<"Harga Lamp: "<<lamp[i].harga<<endl;
         }
         else
         {
            cout<<"anda Salah memasukan watt"<<endl;
            getch();
            goto input;
         }
         

      }
      else
      {
         cout<<"Kode lampu tidak terdaftar"<<endl;
         getch();
         goto input;
         
      }
      
      cout<<"Masukan Jumlah Pembelian: ";cin>>lamp[i].jml_beli;
      lamp[i].subtotal=lamp[i].jml_beli*lamp[i].harga;
      total=total+lamp[i].subtotal;
		cout<<endl;
	}

   //Tampilan Output Program
   system("cls");
   kop();
   garis();
   cout<<"Nama Pemesan: "<<nama<<endl;
   garis();
   cout<<"No. Kode    Merk          Watt     Harga    Beli       Total       \n";
   cout<<"    Lampu   Lampu         Lampu                                    \n";
   garis();
   for(i=1; i<=j_pesan; i++)
   {
      cout<<setiosflags(ios::left)<<setw(5)<<i;
	  cout<<setiosflags(ios::left)<<setw(6)<<lamp[i].kode;
	  cout<<setiosflags(ios::left)<<setw(16)<<lamp[i].merek;
	  cout<<setiosflags(ios::left)<<setw(8)<<lamp[i].watt;
	  cout<<setiosflags(ios::left)<<setw(10)<<lamp[i].harga;
	  cout<<setiosflags(ios::left)<<setw(10)<<lamp[i].jml_beli;
	  cout<<setiosflags(ios::left)<<setw(12)<<lamp[i].subtotal<<endl;
   }
   garis();
   cout<<"Total Bayar: "<<total<<endl;
   cout<<"Total item = "<<j_pesan<<endl;
   cout<<"Ingin input lagi[Y/T]:";cin>>menu;
   if(menu=='y'||menu=='Y')
   {
   	goto input;
   }
   else {
   	exit(0);
   }
}
