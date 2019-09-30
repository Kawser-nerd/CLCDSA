#include<stdio.h>
int main(){
	int i,k,a,s[11]={0},ho=0,t[11]={0};
	scanf ("%d",&a);
	k=2025-a;
	for(i=1;i<10;i++)
	{
	if(k%i==0 && k/i>0 && k/i<10)
	{
	s[ho]=i;
	t[ho]=k/i;
	ho++;
	}
	}
	for (i=0;i<ho;i++){
	printf ("%d x %d\n",s[i],t[i]);
		}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d",&a);
  ^