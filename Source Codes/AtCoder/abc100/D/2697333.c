#include<stdio.h>
int main(void)
{
    long long N,M,i,k,l,m,x,y,z,max,n = 0;
    long long a[1000];
    long long b[1000];
    long long c[1000];
    long long d[1000];
    long long e[1000];
    long long f[1000];
    long long g[1000];
    long long h[1000];
    


    scanf("%d %d",&N,&M);
    for(i = 0;i < N;i++){
    	scanf("%lld %lld %lld",&x,&y,&z);
        a[i] = x + y + z;
        b[i] = x + y - z;
        c[i] = x - y + z;
        d[i] = x - y - z;
        e[i] = -x + y + z;
        f[i] = -x + y - z;
        g[i] = -x - y + z;
        h[i] = -x - y - z;
        x = y = z = 0;
    }

    for(k = 0;k < N;k++){
        for(l = k;l < N;l++){
            if(a[l] > a[k]){
                m = a[l];
                a[l] = a[k];
                a[k] = m;
            }
            if(b[l] > b[k]){
                m = b[l];
                b[l] = b[k];
                b[k] = m;
            }
            if(c[l] > c[k]){
                m = c[l];
                c[l] = c[k];
                c[k] = m;
            }
            if(d[l] > d[k]){
                m = d[l];
                d[l] = d[k];
                d[k] = m;
            }
            if(e[l] > e[k]){
                m = e[l];
                e[l] = e[k];
                e[k] = m;
            }
            if(f[l] > f[k]){
                m = f[l];
                f[l] = f[k];
                f[k] = m;
            }
            if(g[l] > g[k]){
                m = g[l];
                g[l] = g[k];
                g[k] = m;
            }
            if(h[l] > h[k]){
                m = h[l];
                h[l] = h[k];
                h[k] = m;
            }
        }
    }
    for(m = 0;m < M;m++){
        n = n + a[m];
    }
    max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + b[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + c[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + d[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + e[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + f[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + g[m];
    }
    if(n > max)
        max = n;
    n = 0;
    for(m = 0;m < M;m++){
        n = n + h[m];
    }
    if(n > max)
        max = n;

    printf("%lld",max);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%d %d",&N,&M);
           ^
./Main.c:16:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:18:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%lld %lld %lld",&x,&y,&z);
      ^