#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void* a,const void* b){
	return *(const int*)a-*(const int*)b;
}
int main(){
	int n=0;
	cin>>n;
	int *a=new int[n];
    int count=0;
    int i=0;
	while(i<n){
	cin>>a[i++];
	}
	qsort(a,n,sizeof(int),cmp); 
	for(int i=0;i<n;i++){
		int temp=1;
		while(i<(n-1)&&a[i]==a[i+1]){
		   temp++;
		   i++;
	    }
		if(temp&0x01)count+=1 ;
	}
	cout<<count;
}