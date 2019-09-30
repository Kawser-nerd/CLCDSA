#include<stdio.h>
#include<cmath>
int main(){
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	int are1,are2;
	are1=A*B;
	are2=C*D;
	if(are1>=are2){
		printf("%d\n",are1);}
		else{
			printf("%d\n",are2);}
			return 0;
}