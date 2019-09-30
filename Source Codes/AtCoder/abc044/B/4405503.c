#include<stdio.h>
int main(){
	int m[28]={0},i,k,n,a,b,c,ha=0;
	char s[102]={0};
	scanf ("%s",s);
	for (i=0;i<strlen(s);i++){
		m[s[i]-'a']++;
		}
		for (i=0;i<28;i++){
		if(m[i]%2==1){
		ha++;
			break;	
		}
		}
		if(ha==0)
		{
		printf ("Yes");}
		else
		{
			printf ("No");
		}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:6:13: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for (i=0;i<strlen(s);i++){
             ^
./Main.c:6:13: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:6:13: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%s",s);
  ^