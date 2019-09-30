
void swap(int * a, int b,int c){
    int t = a[b];
    a[b] = a[c];
    a[c] = t;

}
int count(int sx, int sy, int tx, int ty){
    if(tx < sx || ty < sy)return 0;
    int d1 = tx-sx;
    int d2 = ty-sy;
    int t1 = (2*d1-d2);
    int t2 = (2*d2-d1);
    if(t1 < 0 || t2 < 0)return 0;
    if(t1 % 3 != 0)return 0;
    if(t2 % 3 != 0)return 0;
    t1 /= 3;
    t2 /= 3;
    long long ret = 1;
    int i, j = 1;
    for(i = t1+1; i<=t1+t2; i++){
        ret *= i;
        for(;j<=t2 && ret %j == 0; j++)
            ret /= j;
        ret %= 10007*10007;
    }
    return ret%10007;
}
int main(){
    int N,R,W,H, i ,j ,k,l,x,y;
    int r[10];
    int c[10];
    int ways[121][121];
    scanf("%d",&N);
    for(i = 1; i<=N; i++){
        scanf("%d%d%d",&H,&W,&R);
        for(j = 0; j<R; j++){
            scanf("%d%d",&r[j],&c[j]);
            for(k = 0; k<j; k++){
                if(r[j] < r[k] || r[j] == r[k] && c[j] < c[k]){
                    swap(r,j,k);
                    swap(c,j,k);
                }
            }
        }
        for(j = 1; j<=H; j++){
            for(k = 1; k<=W; k++){
                ways[j][k] = 0;
            }
        }
        for(j = 0; j<R; j++){
            ways[r[j]][c[j]] = -1;
        }
        ways[1][1] = 1;
        for(j = 1; j<=H; j++){
            for(k = 1; k<=W; k++){
                if(ways[j][k] == -1)continue;
                ways[j][k] %= 10007;
                if(ways[j+1][k+2] != -1)
                    ways[j+1][k+2] += ways[j][k];
                if(ways[j+2][k+1] != -1)
                    ways[j+2][k+1] += ways[j][k];
            }
        }
        printf("Case #%d: %d\n",i,ways[H][W]);
    }
}
