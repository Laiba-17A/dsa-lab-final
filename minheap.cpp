#include<iostream>

using namespace std;

class minheap{
	public:
		int* heap;
		int cap;
		int size;
		
		minheap(int n){
			cap=n;
			size=0;
			heap=new int[cap];
		}
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int left(int i){
			return 2*i + 1;
		}
		
		int right(int i){
			return 2*i + 2;
		}
		
		void heapifyup(int i){
			while(i != 0 && heap[parent(i)]>heap[i]){
				swap(heap[parent(i)],heap[i]);
				i=parent(i);
			}
		}
		
		void heapifydown(int i){
			int l=left(i);
			int r=right(i);
			int smallest=i;
			if(l<size && heap[l]<heap[smallest]){
				smallest=l;
			}
			if(r<size && heap[r]<heap[smallest]){
				smallest=r;
			}
			if(smallest != i){
				swap(heap[i],heap[smallest]);
				heapifydown(smallest);
			}
		}
		
		void insert(int v){
			if(size==cap){
				cout<<"heap full"<<endl;
				return;
			}
			int i=size;
			heap[i]=v;
			size++;
			
			heapifyup(i);
		}
		
		void remove(){
			if(size==0){
				cout<<"heap is empty"<<endl;
			}
			heap[0]=heap[size-1];
			size--;
			if(size==0){
				return;
			}
			heapifydown(0);
		}
		
		void display(){
			cout<<"heap: ";
			for(int i=0;i<size;i++){
				cout << heap[i] << " ";
			}
			cout<<endl;
		}
};

int main(){
	minheap h(10);
	h.insert(45);
	h.insert(30);
	h.insert(20);
	h.insert(50);
	h.insert(10);
	h.insert(60);
	h.display();
	h.remove();
	h.display();
	
	return 0;
}