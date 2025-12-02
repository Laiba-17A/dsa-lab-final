
#include<iostream>

using namespace std;

class hashtable{
	public:
		int size;
		int *arr;
		
		hashtable(int s){
			size=s;
			arr=new int[size];
			for(int i=0;i<s;i++){
				arr[i]=-1;
			}
		}
		
		int hash(int key){
			return key%size;
		}
		
		void insert(int key){
			int idx=hash(key);
			int start=idx;
			while(arr[idx] != -1 && arr[idx] != -2){
				idx=(idx+1)%size;
				if(start==idx){
					cout<<"table is full";
				}
			}
			arr[idx]=key;
		}
		
		bool search(int key){
			int idx=hash(key);
			int start=idx;
			while(arr[idx] != -1 ){
				if(arr[idx]==key){
						cout<<"value found"<<endl;
						return true;
				}
				idx=(idx+1)%size;
				if(start==idx){
					break;
				}
			}
			cout<<"value not found"<<endl;
			return false;
		}
		
		bool remove(int key){
			int idx=hash(key);
			int start=idx;
			
			while(arr[idx] != -1){
				if(arr[idx]==key){
						arr[idx]=-2;
						cout<<"value deleted"<<endl;
						return true;
				}
				idx=(idx+1)%size;
				if(start==idx){
					break;
				}
				
			}
			cout<<"value to be deleted not found"<<endl;
			return false;
		
		}
		
		
		void display(){
			for(int i=0;i<size;i++){
				cout<<arr[i]<<endl;
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
	t1.search(99);
	t1.search(100);
	t1.remove(99);
	t1.display();
	t1.search(99);
	
	return 0;
}