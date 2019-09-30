#include<stdio.h>

int func(int );

int func(int x){
  	if(x%2==0){
      	return x/2;
    }else{
      	return 3*x+1;
    }
}

int
main()
{	
  	int s;
  	scanf("%d",&s);
  	int line[1000000];
  	int i,j;
  	int cnt=1000000;
  	line[0]=s;
      
    for(i=1;;i++){
      	line[i]=func(line[i-1]);
      	for(j=0;j<i;j++){
          	if(line[j]==line[i]){
              	printf("%d",i+1);
              	return 0;
            }
            
        }
      	
    }
      
   
      

    } ./Main.c: In function ‘main’:
./Main.c:17:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&s);
    ^