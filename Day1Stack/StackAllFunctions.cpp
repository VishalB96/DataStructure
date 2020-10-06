#include <iostream>


using namespace std;
int s[100],MaxSize,tos;

void initStack(int size){
	MaxSize = size;
	tos = -1;
}

void push(int e){
	tos++;
	s[tos]=e;
}

int isFull(){
	if(tos==MaxSize){
		return 1;
	}
	else 
	return 0;
}

int pop(){
	int temp;
	temp =s[tos];
	tos--;
	return temp;
}

int isEmpty(){
	if(tos==-1){
		return 1;
	}else{
		return 0;
	}
}

int atTop(){
	return s[tos];
}

void printStack(){
	int i;
	for(i=tos;i>-1;i--){
		cout<<s[i]<<endl;
	}
}


int main()
{
	char ch;
	int size,e;
    cout<<"Enter Size : ";
    cin>>size;
    initStack(size);
    cout<<"Stack of size : "<<size<<" created\n";
    do{
    	cout<<"Enter your choice:\nA.push\nB.pop\nC.At Top\nD.Print Stack\nE.Exit\n";
    	cin>>ch;
    	cout<<endl;
    	switch(ch){
    		case 'A':
    			if(isFull()){
    				cout<<"Stack Full"<<endl;
				}
				else{
					cout<<"Enter value"<<endl;
					cin>>e;
					push(e);		
				}
				break;
			
			case 'B':
				if(isEmpty){
					cout<<"Stack Empty"<<endl;
				}else{
					cout<<"Pop element : "<<pop()<<endl;
				}
				break;
			
			case 'C':
				if(isEmpty()){
					cout<<"Stack empty"<<endl;
				}
				else{
					cout<<atTop()<<endl;
				}
				break;
			
			case 'D':
				if(isEmpty()){
					cout<<"Stack Empty"<<endl;
				}
				else{
					printStack();
				}
				break;
				
			case 'E':
				cout<<"Exiting...."<<endl;
				break;
			default:
				cout<<"Invalid Entery"<<endl;
		}
	}while(ch!='e'||ch!='E');
	cout << endl;
}
