#include<stdio.h>

int main(void){
int no , tem=0 ,res=0;
scanf("%d",&no);
for(int i=1;i<=no;i+=2){
tem=0;
for(int cot=1;cot<=i;cot++){
if (i%cot==0){
tem++;
}
}
if(tem==8){
res++;
}
}
printf("%d",res);
return 0;
}