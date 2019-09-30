#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
const int N=1e6;

int main(){
	int a,b,c;
	int i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<N;i++){
		if((a*i%b)==c){ 
			printf("YES\n");
					break;
		}
	}
	if(i==N) printf("NO\n");
}