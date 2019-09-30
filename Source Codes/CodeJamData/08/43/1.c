double abs(double n){
    return n < 0 ? -n : n;
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int T, N;
    int x[1001];
    int y[1001];
    int z[1001];
    int p[1001];
    int i, j, k, l;
    double d;
    scanf("%d",&T);
    for(i = 1; i<=T; i++){
        scanf("%d",&N);
        for(j = 0; j<N; j++){
            scanf("%d%d%d%d",&x[j],&y[j],&z[j],&p[j]);
        }
        if(N == 1){
            printf("Case #%d: %0.6lf\n",i,0);
            continue;
        }
        double ans = 1e9;
        double xx = 0, yy = 0, zz = 0, step = 1e5;
        int idx;
        while(step > 1e-7){
            double dd = 0;
            for(l = 0; l<N; l++){
                double d = abs((xx-x[l]) / p[l]) + abs((yy-y[l]) / p[l]) + abs((zz-z[l]) / p[l]);
                if (d > dd){
                    dd = d;
                    idx = l;
                }
            }
            if(x[idx] > xx)xx += step;
            else xx -= step;
            if(y[idx] > yy)yy += step;
            else yy -= step;
            if(z[idx] > zz)zz += step;
            else zz -= step;
            step *= 0.999;
            if(dd < ans)ans = dd;
        }
        printf("Case #%d: %0.6lf\n",i,ans);
    }
}
