#include<stdio.h>

int kai(int a){
	int ke[5];
	ke[0]=a%10;a=(a-ke[0])/10;
	ke[1]=a%10;a=(a-ke[1])/10;
	ke[2]=a%10;a=(a-ke[2])/10;
	ke[3]=a%10;a=(a-ke[3])/10;
	ke[4]=a%10;a=(a-ke[4])/10;
	if(ke[0]==ke[4]&&ke[1]==ke[3])return 1;
	else return 0;
}

int main(){
	int a,b,i,ans=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++){
		if(kai(i)==1)ans++;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^