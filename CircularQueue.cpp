#include<iostream>
#include<conio.h>
#define n 10
using namespace std;

struct Queue{
	int R;
	int F;
	int Counter;
	int Q[];
};

void Init(Queue *x)
{
	x->F=0;
	x->R=-1;
	x->Counter= 0;
	x->Q[n];
}

void Insert(Queue *x, int w)
{
	if (x->Counter < n)
	{
		x->R = (x->R + 1)%n;
		x->Q[x->R]=w;
		x->Counter++;
		cout<<"Antiran berhasil ditambahkan\n";
	}
	else
	{
		cout<<"Antiran penuh\n";
	}
	
	
}

void Delete(Queue *x)
{
	if (x->Counter > 0)
	{
		int w;
		x->Q[x->F] = NULL;
		x->F = (x->F + 1) % n;
		x->Counter--;
		cout<<"Antrian Berhasil dihapus\n";
	}
	else
	{
		cout<<"Antrian kosong\n";
	}
}

void display(Queue *x)
{
	int i;
	
	cout<<"[";
	if (x->F > x->R)
	{
		for(i = 0; i < n; i++)
		{
			cout<<x->Q[i]<<" ";
		}
	}else
	{
		for ( i = x->F; i <= x->R ; i++)
		{
			cout<<x->Q[i]<<" ";
		}
	}
	
	cout<<"]"<<endl;
}

int main()
{
	Queue circular;
	
	Init(&circular);
	
	int x, pilih;
	
	
	menu:
	system("cls");
	cout<<"Circular Queue"<<endl;
	cout<<"1. Insert Queue "<<endl;
	cout<<"2. Delete Queue "<<endl;
	cout<<"3. Display Queue "<<endl;
	cout<<"Masukan Pilihan : ";
	cin>>pilih;
	
	switch(pilih){
		case 1:
			system("cls");
			cout<<"Masukan data : "; cin>>x;
			Insert(&circular,x);
			getch();
			goto menu;
		case 2:
			system("cls");
			Delete(&circular);
			getch();
			goto menu;
		case 3:
			system("cls");
			display(&circular);
			getch();
			goto menu;
		default:
			exit;
	}
}
