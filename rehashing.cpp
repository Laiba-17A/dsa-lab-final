
#include<iostream>

using namespace std;

class hashtable{
	public:
		int size;
		int *arr;
		int currs = 0;

		
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
					return;
				}
			}
			arr[idx]=key;
			currs++;
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
						currs--;
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
		float loadfactor() {
		    return (float)currs / size;
		}

		
		void rehash() {
		    int oldSize = size;
		    int* oldArr = arr;
		
		    size = size * 2;      // double size
		    arr = new int[size];  // new bigger array
		
		    // initialize new table
		    for(int i = 0; i < size; i++) {
		        arr[i] = -1;
		    }
		
		    // reinsert valid elements using your existing insert()
		    for(int i = 0; i < oldSize; i++) {
		        if(oldArr[i] != -1 && oldArr[i] != -2) {
		            insert(oldArr[i]);   
		        }
		    }
		
		    delete[] oldArr;
		
		    cout << "Rehash done. New size = " << size << endl;
		}

};

int main(){
	hashtable t1(10);
	t1.insert(20);
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
	t1.insert(50);
	t1.insert(30);
//	t1.insert(15);
	t1.display();
	float lf=t1.loadfactor();
	if(lf > 0.6){
		cout<<"load factor is : "<<lf<<endl;
		t1.rehash();
		t1.display();
	}
	
	
	return 0;
}