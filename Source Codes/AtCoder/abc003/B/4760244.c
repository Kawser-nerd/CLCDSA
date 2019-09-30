#include<stdio.h>
#include<string.h>
int main(void){
  char s[10],t[10];
  int i,sum;
	sum=0;
  scanf("%s",s);
  scanf("%s",t);
  for(i=0;i<strlen(s);i++){
   if(s[i]==t[i]){
       sum++;
   }else if(s[i]=='@'){
   	 if (t[i]=='@' || t[i]=='a' || t[i]=='t' 
          || t[i]=='c' || t[i]=='o' || t[i]=='d' || t[i]=='e' || t[i]=='r'){
        sum++;
      }
    }
    else if (t[i]=='@'){
      if (s[i]=='@' || s[i]=='a' || s[i]=='t' 
          || s[i]=='c' || s[i]=='o' || s[i]=='d' || s[i]=='e' || s[i]=='r'){
        sum++;
      }
    }
  }
		if(sum==strlen(s)){ printf("You can win\n");
			}else{ printf("You will lose\n");
			}
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^