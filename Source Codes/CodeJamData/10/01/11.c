#include<stdio.h>
int main(){
	int Tc;
	scanf("%d",&Tc);
	int k;
	for(k=1;k<=Tc;k++){
		int a,b;
		scanf("%d%d",&a,&b);
		if((b&((1<<a)-1))==((1<<a)-1))printf("Case #%d: ON\n",k);
		else printf("Case #%d: OFF\n",k);
	}
	return 0;
}
