#include<stdio.h>
int main(void){
    int num;
    scanf("%d",&num);
    int x[num];
    int i,j;
    int count=0;
  int temp=0;
    for(i=0;i<num;i++){
        scanf("%d",&x[i]);
    }
   for(i=0;i<num;i++){
        for(j=i;j<num;j++){
            if(x[i]>x[j]){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
  
  for(i=0;i<num;i++){
    if(x[i]>x[i-1]) count++;
  }
printf("%d",count);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[i]);
         ^