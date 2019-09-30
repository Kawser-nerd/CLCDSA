#include<stdio.h>
int main(void){
  int num,value;
  scanf("%d %d",&num,&value);
    int man=10000;
    int go=5000;
    int sen=1000;
    int nman,ngo,nsen;
    int ans=0;
    int flag=0;

    for(nman=0;nman<=num;nman++){
        for(ngo=0;ngo<=num;ngo++){
            nsen=num-nman-ngo;
         if(nsen<0)break;
            ans=nsen*1000+ngo*5000+nman*10000;
            if(value==ans){
              if(flag==1){
                break;
             	 }else{
                flag=1;
                printf("%d %d %d",nman,ngo,nsen);
              }
            }
        }
    }
if(flag==0){
    printf("%d %d %d",-1,-1,-1);
}
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&num,&value);
   ^