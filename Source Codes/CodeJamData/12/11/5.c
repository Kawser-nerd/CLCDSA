#include<stdio.h>

double correct[100001],firsterr[100001];

int main(int argc,char*argv[]){
int a,b,e,f,typed,total;
double expect,d;

scanf("%d",&f);
for(e=1;e<=f;e++){
scanf("%d%d",&typed,&total);

d=1;
for(a=0;a<typed;a++){
scanf("%lf",correct+a);
firsterr[a]=d;
d*=correct[a];
}
firsterr[typed]=d;
expect=total+2;//press enter

for(b=0;b<=typed;b++){// b backspace

d=(2*b+total-typed+1)+((1-firsterr[typed-b])*(1+total));
if(expect>d)expect=d;
}
printf("Case #%d: %lf\n",e,expect);
}
return 0;
}
