#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){
	int a[200005];
	int n,t,i,T=0;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		if((a[i]-a[i-1])>=t) T=T+t;
		if((a[i]-a[i-1])<t) T=T+(a[i]-a[i-1]);   	   
	}
	T=T+t;
	printf("%d\n",T);
}