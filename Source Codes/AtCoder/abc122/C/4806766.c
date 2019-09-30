#include <stdio.h>
int main(void){
    int N,Q,l,r,i,k;
    scanf("%d",&N);
    scanf("%d",&Q);
    char S[N];
    int A[N-1];
    scanf("%s",&S);
    
    if(S[0] == 'A' && S[1] == 'C') A[0] = 1;
    else A[0] = 0;
    
    for(k=1;k<N-1;k++) {
        if(S[k] == 'A' && S[k+1] == 'C' && k>0) A[k] = A[k-1] + 1;
        else A[k] = A[k-1];
    }
    
    for(i=0;i<Q;i++){
        scanf("%d",&l);
        scanf("%d",&r);
        if(l>1) printf("%d\n",A[r-2]-A[l-2]);
        else printf("%d\n",A[r-2]);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(N)]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&Q);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l);
         ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r);
         ^