#include<iostream>
using namespace std;

class node{
	public:
		int val;
		node* next;
		
		node(int v){
			val=v;
			next=nullptr;
		}
};

class stack{
	public:
		node* top=nullptr;
		
		void push(int v){
			node* n=new node(v);
			if(top==nullptr){
				top=n;
			}
			else{
				node* temp=top;
				top=n;
				top->next=temp;
			}
		}
		
		void pop(){
			if(top==nullptr){
				cout<<"stack is empty"<<endl;
			}
			else{
				node* temp=top;
				top=top->next;
				delete temp;
			}
		}
		
		void peek(){
			if(top==nullptr){
				cout<<"stack is empty";
			}
			else{
				cout<<"top of stack is "<<top->val<<endl;
			}
		}
		
		void display(){
			if(top==nullptr){
				cout<<"stack is empty";
			}
			else{
				node* temp=top;
				while(temp!=nullptr){
					cout<<temp->val<<endl;
					temp=temp->next;
				}
				
			}
		}
};

void validator(string a,string p){
	stack s;
	int n=a.length();
	for(int i=0;i<n;i++){
		if(a[i]==p[0]){
			s.push(2);
		}
		else if(a[i]==p[1]){
			if(s.top==nullptr){
				cout<<"not valid";
				return;
			}
			s.pop();
		}
		else{
			continue;
		}
	}
	if(s.top==nullptr){
		cout<<"valid";
		return;
	}	
	else{
		cout<<"not valid";
		return;
	}
}

int main(){

	string a="a+b)";
	string p="()";
	validator(a,p);
	
	return 0;
	
}