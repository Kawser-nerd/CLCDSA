#include <stdio.h>
#include <stdlib.h>

long long int getans(int n,long long int x);
long long int a[50],p[50];

 
int main(void){
 
  	int n,i;
  	unsigned long long int x;
  	
  	scanf("%d %lld",&n,&x);
	
  	a[0]=1;
  	p[0]=1;
  	for(i=1;i<50;i++){
    	a[i] = 2*a[i-1]+1;
      	p[i] = 2*p[i-1]+3;
    }
	printf("%lld",getans(n,x));
  
	return 0;
}

long long int getans(int n,long long int x){

	if(n == 0){
    	if(x <= 0)
      		return 0;
  		else
          	return 1;
    }
 	else if(x <=1+  p[n-1]){
    	return getans(n-1,x-1);
    }
  	else{
    	return a[n-1] +1  + getans(n-1, x-2-p[n-1]);
    }


} ./Main.c: In function ‘main’:
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %lld",&n,&x);
    ^