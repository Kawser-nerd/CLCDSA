#include<stdio.h>

int main(){
long a,b,c=0,d=0,e=0,i;
scanf("%ld",&a);
for(i=0;i<a;i++){
scanf("%ld",&b);
if(c==0) c=b;
else{
if(c<b){
e++;
c=b;
}else{
d+=e*(e+1)/2;
e=0;
c=b;
}
}
}
d+=e*(e+1)/2;
d+=a;
printf("%ld\n",d);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld",&a);
 ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld",&b);
 ^