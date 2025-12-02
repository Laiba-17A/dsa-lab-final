#include<iostream>
using namespace std;

void bruteforce(string str,string tar){
	int n1=str.length();
	int n2=tar.length();
	
	for(int i=0;i<=n1-n2;i++){
		int j=0;
		while(j<n2 && str[i+j]==tar[j]){
			j++;
		}
		if(j==n2){
			cout<<"pattern found at index "<<i<<endl;
			return;
		}
	}
	cout<<"not found"<<endl;
}

int main(){
	string str1="my name is laiba";
	string pat="laibs";
	bruteforce(str1,pat);
	return 0;
}