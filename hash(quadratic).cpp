
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
			int i=0;
			while(i<size){
				int newidx=(idx+(i*i))%size;
				if(arr[newidx] == -1 || arr[newidx] == -2){
					arr[newidx]=key;
					return;
				}
				i++;
			}
			cout<<"table full"<<endl;
			
		}
		
		bool search(int key){
			int idx = hash(key);
		    int i = 0;
		
		    while(i < size) {                      
		        int newIdx = (idx + i*i) % size;
		
		        if(arr[newIdx] == key) {            
		                      
		            cout << "Value found " << key << endl;
		            return true;
		        }
		
		        if(arr[newIdx] == -1)              
		            break;
		
		        i++;                                
		    }
		
		    cout << "Value not found: " << key << endl;
		    return false;
		}
		
		bool remove(int key) {
		    int idx = hash(key);
		    int i = 0;
		
		    while(i < size) {                      
		        int newIdx = (idx + i*i) % size;
		
		        if(arr[newIdx] == key) {            
		            arr[newIdx] = -2;             
		            cout << "Value deleted: " << key << endl;
		            return true;
		        }
		
		        if(arr[newIdx] == -1)              
		            break;
		
		        i++;                                
		    }
		
		    cout << "Value to be deleted not found: " << key << endl;
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