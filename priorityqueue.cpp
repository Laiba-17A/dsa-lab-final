#include<iostream>
using namespace std;

class node{
	public:
		int val;
		node* next;
		int pri;
		
		node(int v,int p){
			val=v;
			pri=p;
			next=nullptr;
		}
};

class PQ{
	public:
		node* head=nullptr;
		node* tail=nullptr;
		
		void enqueue(int v,int p){
			node* n=new node(v,p);
			if(head==nullptr ){
				head=n;
				tail=n;
			}
			else if(p>head->pri){
				n->next=head;
				head=n;
			}
			else{
				node* temp=head;
				while(temp->next != nullptr && temp->next->pri >=p){
					temp=temp->next;
				}
				n->next=temp->next;
				temp->next=n;
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
	PQ q;
	q.enqueue(2,7);
	q.enqueue(3,1);
	q.enqueue(4,5);
	q.enqueue(5,2);
	q.display();
	cout<<endl;
	q.dequeue();
	q.dequeue();
	q.display();
	cout<<endl;
	
	return 0;
}