#include<stdio.h>

int main(){
long n;scanf("%ld",&n);
int dsum=0,i;
if(n==2||n==3||n==5){
puts("Prime");
return 0;
}
if(n==1){
puts("Not Prime");
return 0;
}
if(n%2==0){
puts("Not Prime");
}
else if(n%10==5){
puts("Not Prime");
}
else {
while(n!=0){
int tmp=n%10;
n=(n-tmp)/10;
dsum+=tmp;
}
if(dsum%3==0){
puts("Not Prime");
}
else puts("Prime");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long n;scanf("%ld",&n);
        ^