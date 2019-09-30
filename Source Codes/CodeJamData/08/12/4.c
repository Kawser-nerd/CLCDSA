int like[2100][2100];
int cnt[2100];
int happy[2100];
int malted[2100];
int main(){
    int C,N, M, T, X, Y;
    int i, j, k, changed, unhappy;
    scanf("%d",&C);
    for(i = 1; i<=C; i++){
        for(j = 0; j<2100; j++){
            malted[j] = 0;
            cnt[j] = 0;
        }
        scanf("%d%d",&N,&M);
        for(j = 0; j<M; j++){
            scanf("%d",&T);
            cnt[j] = T;
            for(k = 0; k<T; k++){
                scanf("%d%d",&X,&Y);
                like[j][k] = X * (Y*2-1);//positive for malted
            }
        }
        changed = 1;
        while(changed){
            unhappy = 0;
            changed = 0;
            for(j = 0; j<M; j++){
                happy[j] = 0;
            }
            for(j = 0; j<M; j++){
                for(k = 0; k<cnt[j]; k++){
                    if(like[j][k] > 0 && malted[like[j][k]]){
                        happy[j] = 1;
                    }else if(like[j][k] < 0 && !malted[-like[j][k]]){
                        happy[j] = 1;
                    }
                }
            }
            for(j = 0; j<M; j++){
                if(!happy[j]){
                    unhappy ++;
                    for(k = 0; k<cnt[j]; k ++){
                        if(like[j][k] > 0 && !malted[like[j][k]]){
                            malted[like[j][k]] = 1;
                            changed = 1;
                        }
                    }
                }
            }
        }
        if(unhappy)
            printf("Case #%d: IMPOSSIBLE\n",i);
        else{
            printf("Case #%d:",i);
            for(j = 1; j<=N; j++){
                printf(" %d",malted[j]);
            }
            printf("\n");
        }
    }
}
