int min(int a, int b){
    if(a<b)return a;
    else return b;
}
int main(){
    int N, M, V, i, j, k, a,b,c,d;
    int value[10010];
    int change[10010];
    int cost0[10010];
    int cost1[10010];
    scanf("%d",&N);
    for(i = 1; i<=N; i++){
        scanf("%d%d",&M,&V);
        for(j = 0; j<(M-1)/2; j++){
            scanf("%d",&value[j]);
            scanf("%d",&change[j]);
        }
        for(j = (M-1)/2;j<M; j++){
            scanf("%d",&value[j]);
            cost0[j] = cost1[j] = 1000000;
            if(value[j])cost1[j] = 0;
            else cost0[j] = 0;
        }
        int m = 10000;
        for(j = (M-1)/2-1;j>=0;j--){
            cost0[j] = 1000000;
            cost1[j] = 1000000;
            a = cost1[j*2+1]+cost1[j*2+2];
            b = cost1[j*2+1]+cost0[j*2+2];
            c = cost0[j*2+1]+cost1[j*2+2];
            d = cost0[j*2+1]+cost0[j*2+2];
            if(value[j]){//AND
                cost1[j] = min(cost1[j],a);
                cost0[j] = min(cost0[j],b);
                cost0[j] = min(cost0[j],c);
                cost0[j] = min(cost0[j],d);
            }else{
                cost1[j] = min(cost1[j],a);
                cost1[j] = min(cost1[j],b);
                cost1[j] = min(cost1[j],c);
                cost0[j] = min(cost0[j],d);
            }
            if(change[j]){
                if(value[j]){//AND
                    cost1[j] = min(cost1[j],a+1);
                    cost1[j] = min(cost1[j],b+1);
                    cost1[j] = min(cost1[j],c+1);
                    cost0[j] = min(cost0[j],d+1);
                }else{
                    cost1[j] = min(cost1[j],a+1);
                    cost0[j] = min(cost0[j],b+1);
                    cost0[j] = min(cost0[j],c+1);
                    cost0[j] = min(cost0[j],d+1);
                }
            }
        }
        if(V)m = cost1[0];
        else m = cost0[0];
        if(m >=10000)
            printf("Case #%d: IMPOSSIBLE\n",i);
        else
            printf("Case #%d: %d\n",i,m);


    }

}
