#include<iostream>

using namespace std;

class maxheap{
	public:
		int* heap;
		int cap;
		int size;
		
		maxheap(int n){
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
			while(i != 0 && heap[parent(i)]<heap[i]){
				swap(heap[parent(i)],heap[i]);
				i=parent(i);
			}
		}
		
		void heapifydown(int i){
			int l=left(i);
			int r=right(i);
			int largest=i;
			if(l<size && heap[l]>heap[largest]){
				largest=l;
			}
			if(r<size && heap[r]>heap[largest]){
				largest=r;
			}
			if(largest != i){
				swap(heap[i],heap[largest]);
				heapifydown(largest);
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
			swap(heap[0],heap[size-1]);
			size--;
			if(size==0){
				return;
			}
			heapifydown(0);
		}
		
		void display(){
			cout<<"heap: ";
			for(int i=0;i<cap;i++){
				cout << heap[i] << " ";
			}
			cout<<endl;
		}
};

int main(){
	maxheap h(10);
	h.insert(45);
	h.insert(30);
	h.insert(20);
	h.insert(50);
	h.insert(10);
	h.insert(60);
	h.insert(70);
	h.insert(55);
	h.insert(85);
	h.insert(95);

	h.display();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.display();
	
	return 0;
}