#include<stdio.h>

int main(){
	int k,a,b;
	while(scanf("%d%d%d",&k,&a,&b)==3){
		if(a>b) printf("%d\n",0);
		else if(a!=b&&k==1) printf("%d\n",0);
		else if(a==b&&k==1) printf("%d\n",1);
		else printf("%lld\n",(long long)(k-2)*(b-a)+1); 
	}
	return 0;
}