#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,c,a1,b1,c1;
int main(){
		cin>>a>>b>>c;
		int f=0;
		for(int i=0;i<100;i++){
			if(a%2!=0||b%2!=0||c%2!=0){
				if(i==0){
				printf("0");
				return 0;
				
				}
				f=i;
				break;
			}
			a1=b/2+c/2;
			b1=a/2+c/2;
			c1=b/2+a/2;
			a=a1;
			b=b1;
			c=c1;
		}
	if(f)
		printf("%d",f);
	else 
		printf("-1");
}