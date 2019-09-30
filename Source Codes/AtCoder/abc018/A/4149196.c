#include <stdio.h>

int main(void){
    int A,B,C,rank[3]={1,1,1},i;
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);
    if(A<B) rank[0]++;
    else    rank[1]++;
    if(B<C) rank[1]++;
    else    rank[2]++;
    if(C<A) rank[2]++;
    else    rank[0]++;
    for(i=0;i<3;i++){
        printf("%d\n",rank[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&B);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&C);
     ^