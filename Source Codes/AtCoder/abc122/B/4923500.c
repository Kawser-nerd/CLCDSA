#include<stdio.h>
   
   int main(void)
   {
           int n=0,s=0;
           char c;
   
           while(scanf("%c",&c)!=EOF)
           {
                  if((c=='A')||(c=='G')||(c=='T')||(c=='C')){
                          n=n+1;
                  }
                  else if(s<n){
                          s=n;
                          n=0;
                  }
          }
  
          printf("%d\n",s);
          return 0;
  }