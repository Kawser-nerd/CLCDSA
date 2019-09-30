#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main(){
	int n,j=0,k = 1;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i]==i)
		b[k++]=i;
	}
	for(int i = 1;i < k;i++){
		if(a[b[i]]==b[i]){
			int t=a[b[i]+1];
			a[b[i]+1]=a[b[i]];
			a[b[i]]=t;
			if(i == k-1){
				b[i]=b[i-1];
			}
		j++;
		}
	}
	printf("%d\n",j);
}