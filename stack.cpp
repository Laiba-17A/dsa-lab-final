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
 int main(){
	stack s;
	s.push(20);
	s.push(30);
	s.display();
	s.pop();
	s.display();
	
	
	return 0;
	
}