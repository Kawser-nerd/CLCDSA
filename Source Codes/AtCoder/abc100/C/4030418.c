#include<stdio.h>
#include<math.h>

int main(){
    int N;
    int i;
    int kaisu=0;
    scanf("%d",&N);
    int AN[N];
    for(i=0;i<=N-1;i++){
        scanf("%d",&AN[i]);
    }
    for(i=0;i<=N-1;i++){
        while(1){
            if(AN[i]%2==0){
                kaisu++;
                AN[i]=AN[i]/2;
            }
            else{
                break;
            }
        }
    }
    printf("%d",kaisu);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&AN[i]);
         ^