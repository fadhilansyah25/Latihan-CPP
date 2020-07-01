#include<iostream>
using namespace std;

int maxstack;

struct STACK{
	int top;
	int array[300];
};

void init(STACK *s){
	s->top=-1;
	s->array[maxstack];
}

bool penuh(STACK *s){
	if(s->top == maxstack)
		return true;
	else
		false;
}

bool kosong(STACK *s){
	if(s->top == -1)
		return true;
	else
		return false;
}

void push(int x, STACK *s){
	if(penuh(s) == false){
		(s->top)++;
		s->array[s->top] = x;
	}
}

void pop(STACK *s){
	if(kosong(s) == false){
		int buang = s->array[s->top];
		cout<<buang;
		(s->top)--;
	}
}

main()
{
	STACK tumpukan;
	int input, i, n, sisa;
	cout<<"Masukan bilangan yang akan di jadikan biner : ";cin>>input;
	
	for(i = 1, n=input ; n>0; i++){
		n=n/2;
		maxstack=i;
	} 
	
	init(&tumpukan);
	
	for(i=0; i<maxstack; i++){
		sisa=input%2;
		push(sisa,&tumpukan);
		input=input/2;
	}
	
	for(i=0; i<maxstack; i++){
		pop(&tumpukan);
	}
	cout<<endl;
}

