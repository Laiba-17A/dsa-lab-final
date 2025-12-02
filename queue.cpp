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

class queue{
	public:
		node* head=nullptr;
		node* tail=nullptr;
		
		void enqueue(int v){
			node* n=new node(v);
			if(head==nullptr){
				head=n;
				tail=n;
			}
			else{
				tail->next=n;
				tail=tail->next;
			}
		}
		
		void dequeue(){
			if(head==nullptr){
				cout<<"queue is empty"<<endl;
			}
			else{
				node* temp=head;
				head=head->next;
				delete temp;
			}
		}
		
		
		void display(){
			if(head==nullptr){
				cout<<"queue is empty";
			}
			else{
				node* temp=head;
				while(temp!=nullptr){
					cout<<temp->val<<endl;
					temp=temp->next;
				}
				
			}
		}
};

int main(){
	queue q;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	cout<<endl;
	q.dequeue();
	q.dequeue();
	q.display();
	cout<<endl;
}