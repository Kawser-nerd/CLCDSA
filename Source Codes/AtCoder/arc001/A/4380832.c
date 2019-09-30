#include<stdio.h>

int main(){
	int n,c[4]={0},i,min=1000,max=0;
	char s[101];
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++)c[s[i]-'1']++;
	if(c[0]>max)max=c[0];
	if(c[1]>max)max=c[1];
	if(c[2]>max)max=c[2];
	if(c[3]>max)max=c[3];
	if(c[0]<min)min=c[0];
	if(c[1]<min)min=c[1];
	if(c[2]<min)min=c[2];
	if(c[3]<min)min=c[3];
	printf("%d %d\n",max,min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s",&n,s);
  ^