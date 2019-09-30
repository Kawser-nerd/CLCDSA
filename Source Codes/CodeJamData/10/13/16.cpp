#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int win[2000000];

long long same(int a1,int a2,int b1,int b2){
	if (max(a1,b1)>min(a2,b2)) return 0;
	return min(a2,b2)-max(a1,b1)+1;
}

long long calc(int a1,int a2,int b1,int b2){
	long long ret=0;
	for (int i=a1;i<=a2;++i){
		int r=win[i];
		int l=0;
		ret+=same(l,r,b1,b2);
	}
	return ret;
}

int main(){
	int k=1;
	win[1]=0;win[2]=1;win[3]=1;
	for (int i=4;i<=1000000;++i){
		for (;k<i;++k)
		    if (i<k+k && i-k<=win[k]) break;
		win[i]=k-1;
	}
	int T,I=0;
	scanf("%d",&T);
	while (T--){
		int a1,a2,b1,b2;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		cout << "Case #" << ++I << ": " ;
		cout << calc(a1,a2,b1,b2)+calc(b1,b2,a1,a2) << endl;
	}
}
