#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	//?????
	char a[200010];
	long int alphabet[30];
	int i,j,k;
	long int len;
	long int ans;
	
	//????????
	scanf("%s",&a);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<30;i++){
		alphabet[i]=0;
	}
	
	len=strlen(a);
	for(i=0;i<len;i++){
		alphabet[a[i]-'a']++;
	}
	
	ans=len*(len-1)/2+1;
	for(i=0;i<26;i++){
//		if(alphabet[i]!=0) printf("%c?%d?\n",'a'+i,alphabet[i]);
		ans=ans-alphabet[i]*(alphabet[i]-1)/2;
	}
	
	
	
//	printf("??????\n");
	
	//??
	printf("%ld",ans);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[200010]’ [-Wformat=]
  scanf("%s",&a);
        ^
./Main.c:28:6: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  len=strlen(a);
      ^
./Main.c:28:6: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:28:6: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&a);
  ^