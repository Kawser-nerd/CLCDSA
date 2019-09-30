#include <stdio.h>

int main(void){
	
	int j,i,n,v;
	char b[100];
	
	n = 0;
	
	scanf("%d\n%s",&j,&b);
	
	if(j%2==0)n=n+1;
	
	if(b[j/2]!='b')n=n+1;
	
	for(i=0;i<j;i++){
		if(b[i] == 'a'){
			
			if(b[i+1] != 'b')n=n+1;
			
		} else if(b[i] == 'b'){
			
			if(b[i+1] != 'c')n=n+1;
			
		} else if(b[i] == 'c'){
			
			if(b[i+1] != 'a')n=n+1;
			
		} else if(b[i] != 'a'||b[i]!='b'||b[i]!='c'){
			
			n = n + 1;
			
		}
	}
	
	if(n==1)printf("%d\n",(j-1)/2);
	if(n!=1)printf("-1\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
  scanf("%d\n%s",&j,&b);
        ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%s",&j,&b);
  ^