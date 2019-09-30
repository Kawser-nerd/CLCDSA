#include <stdio.h>
#include <math.h>
#include <string.h>
int _max(int x,int y){return x>y?x:y;}
int main(){
	int a,b;
	int k1=-9999999,k2;
	//?a-b???????a?????b???? 
	scanf("%d%d",&a,&b);
	k2=a%100+900-b;k1=_max(k1,k2);
	k2=((a/100)*100+a%10+90)-b;k1=_max(k1,k2);
	k2=a-a%10+9-b;k1=_max(k1,k2);
	//?????a??? 
	k2=a-(b%100+100);k1=_max(k1,k2);
	k2=a-((b/100)*100+b%10);k1=_max(k1,k2);
	k2=a-(b-b%10);k1=_max(k1,k2);
	//?????b??? 
	printf("%d\n",k1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^