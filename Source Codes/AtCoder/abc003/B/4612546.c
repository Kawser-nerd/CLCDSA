#include <stdio.h>
int main(){
	char s[11],t[11];
	scanf ("%s%s",s,t);
	int i,a=0;
	for (i=0;s[i]!=0;i++){
		if(s[i]==t[i]){
		}
		else if(s[i]=='@'){	
		 if(t[i]=='a' || t[i]=='t' || t[i]=='c' || t[i]=='o' || t[i]=='r' || t[i]=='d' || t[i]=='e' || t[i]=='r')
		 {	
		 }
		 else
		 {
		 	a++;
		 	break;
		 }
		 }
		 else if(t[i]=='@'){	
		 if(s[i]=='a' || s[i]=='t' || s[i]=='c' || s[i]=='o' || s[i]=='r' || s[i]=='d' || s[i]=='e' || s[i]=='r')
		 {	
		 }
		 else
		 {
		 	a++;
		 	break;
		 }
		 }
		 else
		 {
		 	a++;
		 	break;
		 }
		}
		if(a>0){
		printf ("You will lose\n");
			}
		else
		{
		printf ("You can win\n");
		}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%s%s",s,t);
  ^