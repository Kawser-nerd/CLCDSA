int main(){
    int N, M, C, A;
    int i, j, k;
    scanf("%d",&C);
    for(i = 1; i<=C; i++){
        scanf("%d%d%d",&N,&M,&A);
        if(N*M < A){
            printf("Case #%d: IMPOSSIBLE\n",i);
            continue;
        }
        j = (A+N-1)/N;
        k = (N-A%N)%N;
        printf("Case #%d: %d %d %d %d %d %d\n",i,0,0,k,j,N,1);
    }
}
