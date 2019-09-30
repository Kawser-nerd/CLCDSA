#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))


int main(void)
{
	//?????
	char x[200010];
	int a,b;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int sum=0;
	llong int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%s",&x);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	len=strlen(x);
	a=0;
	b=0;
	for(i=0;i<len;i++){
		if(b>0){
			if(x[i]=='T') b--;
			if(x[i]=='S') b++;
		}else{
			if(x[i]=='T') a++;
			if(x[i]=='S') b++;
		}
	}
	
//	printf("??????\n");
	//??
	
	printf("%d",a*2);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:28:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[200010]’ [-Wformat=]
  scanf("%s",&x);
        ^
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&x);
  ^