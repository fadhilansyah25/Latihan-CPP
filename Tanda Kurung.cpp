#include<iostream>
#include<string>
using namespace std;

struct STACK{
	int top;
	char array[];
};

struct STACK karung;
bool check(STACK tumpukan, string x, int n)
{
	tumpukan.top = -1;
	tumpukan.array[n];
	int i;
	char buang;
	
	for(i=0; i<n; i++)
	{
		if(x[i] =='(')
		{
			if(tumpukan.top < n-1 )
			{
				tumpukan.top++;
				tumpukan.array[tumpukan.top] = x[i];
			}
			else
			{
				break;
			}
		}
		else if(x[i] ==')')
		{
			if(tumpukan.top > -1)
			{
				buang = tumpukan.array[tumpukan.top];
				tumpukan.top--;
			}
			else if(tumpukan.top == -1)
			{
				tumpukan.top--;
				break;
			}
		}	
	}
	
	cout<<tumpukan.top<<endl;
	
	if(tumpukan.top == -1)
		return true;
	else
		return false;
}

main(){
	string kata;
	char pilihan;
	
	do
	{
		cout<<"Masukan Operasi Matematika : "; cin>>kata;
		int n;
		n=kata.size();
	
		if(check(karung, kata, n) == true)
		{
			cout<<"Tanda kurung sudah benar"<<endl;
		}
		else
		{
			cout<<"Tanda kurung masih salah"<<endl;
		}
		
		cout<<"Masih mau ngecek?? [Y/T] : ";cin>>pilihan;
		pilihan = tolower(pilihan);
		cout<<endl;
	}while(pilihan == 'y');
	
}
