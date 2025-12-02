#include<iostream>

using namespace std;

int partition(int arr[],int st, int end){
	int idx=st-1;
	int pivot=arr[end];
	for(int j=st;j<end;j++){
		if(arr[j]<=pivot){
			idx++;
			swap(arr[j],arr[idx]);
		}
	}
	idx++;
	swap(arr[end],arr[idx]);
	return idx;
}

void quicksort(int arr[],int start,int end){
	 if(start<end){
	 	int pivot=partition(arr,start,end);
	 	quicksort(arr,start,pivot-1);
	 	quicksort(arr,pivot+1,end);
	 }
	 else{
	 	return;
	 }
}

void merge(int arr[],int left,int mid,int right){
	int s1=mid-left+1;
	int s2=right-mid;
	int l[s1];
	int r[s2];
	for(int i=0;i<s1;i++){
		l[i]=arr[left+i];
	}
	for(int j=0;j<s2;j++){
		r[j]=arr[mid+1+j];
	}
	int k=left;
	int i=0;
	int j=0;
	while(i<s1 && j<s2){
		if(l[i]<=r[j]){
			arr[k]=l[i];
			i++;
		}
		else{
			arr[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<s1){
		arr[k]=l[i];
		i++;
		k++;
	}
	while(j<s2){
		arr[k]=r[j];
		k++;
		j++;
	}
	
}

void mergesort(int arr[],int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
	
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		
		merge(arr,left,mid,right);
	}
}


int main(){
	int array[6]={1,4,6,7,2,3};
	
	cout<<"original array: "<<endl;
	for(int i=0;i<6;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	quicksort(array,0,5);
	//display
	cout<<"after quick sort"<<endl;
	for(int i=0;i<6;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"after merge sort"<<endl;
	int arr2[6]={1,4,6,7,2,3};
	mergesort(arr2,0,5);\
	
	for(int i=0;i<6;i++){
		cout<<arr2[i]<<" ";
	}
	return 0;
	
}