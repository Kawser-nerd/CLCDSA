#include <stdio.h>
int main (){
char s[1001];
int i,n=0,k=0,w=0,e=0;
scanf ("%s",s);	
for (i=0; s[i]!=0;i++){
	if(s[i]=='N'){
	n++;}
	else if(s[i]=='S'){
	k++;}
	else if(s[i]=='W'){
	w++;}
	else if(s[i]=='E'){
	e++;}
	}
	
	if (n>0 && k>0 && w==0 && e==0){
		printf ("Yes");
		}
		else if (n==0 && k==0 && w>0 && e>0){
		printf ("Yes");
		}
		else if (n>0 && k>0 && w>0 && e>0){
		printf ("Yes");
		}
		else
		{
			printf ("No");
		}	
	return 0;
		} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s",s); 
 ^