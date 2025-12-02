
#include<iostream>

using namespace std;

struct node {
    int key;
    node* next;
    node(int k) : key(k), next(nullptr) {}
};

class hashtable{
	public:
		int size;
		node **arr;
		
		hashtable(int s){
			size=s;
			arr=new node*[size];
			for(int i=0;i<s;i++){
				arr[i]=nullptr;
			}
		}
		
		int hash(int key){
			return key%size;
		}
		
		void insert(int key){
			int idx=hash(key);
			node* newn=new node(key);
			newn->next=arr[idx];
			arr[idx]=newn;
					}
		
		bool search(int key){
			int idx=hash(key);
			node* temp=arr[idx];
			while(temp != nullptr){
				if(temp->key==key){
					cout<<"found"<<endl;
					return true;
				}
				temp=temp->next;
			}
			cout<<"not found"<<endl;
			return false;
		}
		
		bool remove(int key){
			int idx=hash(key);
			node* temp=arr[idx];
			node* prev=nullptr;
			while(temp != nullptr){
				if(temp->key==key){
					if(prev==nullptr){
						arr[idx]=temp->next;
	
					}
					else{
						prev->next=temp->next;
					}
					delete temp;
					cout<<"deleted"<<endl;
					return true;
				
				}
				prev=temp;
				temp=temp->next;
			}
			cout<<"value to be deleted not found"<<endl;
			return false;
		}
		
		
		void display(){
			cout<<"hash table "<<endl;
			for(int i=0;i<size;i++){
				node* temp = arr[i];
	            while(temp) {
	                cout << temp->key <<" ";
	                temp = temp->next;
	            }
	            cout << "NULL" << endl;
        	}
		}
		
};

int main(){
	hashtable t1(10);
	t1.insert(2);
	t1.insert(65);
	t1.insert(42);
	t1.insert(5);
	t1.insert(9);
	t1.insert(99);
	t1.display();
	cout<<endl;
	t1.search(99);
	t1.search(100);
	t1.remove(9);
	t1.display();
	t1.search(99);
	
	return 0;
}