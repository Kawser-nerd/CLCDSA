#include<stdio.h>
#include<string.h>

int r[3][3];

int main() {
    int x,y,a,b,c,d,n,m,N,i,j,l,k,cs=0;
    long long ret;

    for(scanf("%d",&N);N--;) {
        scanf("%d %d %d %d %d %d %d %d",&n,&a,&b,&c,&d,&x,&y,&m);
        memset(r,0,sizeof(r));
        ret=0;
        for(i=0;i<n;i++) {
            r[x%3][y%3]++;
            x=((long long)a*x+b)%m;
            y=((long long)c*y+d)%m;
        }
        for(i=0;i<3;i++)
            for(j=0;j<3;j++) {
                for(k=0;k<3;k++)
                    for(l=0;l<3;l++)
                        if (k!=i || l!=j) {
                            x=(6-i-k)%3,y=(6-j-l)%3;
                            if ((x!=i || y!=j) && (x!=k || y!=l)) 
                                ret+=(long long)r[i][j]*r[k][l]*r[x][y];
                            else ret+=(long long)r[i][j]*r[k][l]*(r[x][y]-1)/2;
                        }
                ret+=(long long)r[i][j]*(r[i][j]-1)*(r[i][j]-2);
            }
        printf("Case #%d: %lld\n",++cs,ret/6);
    }
    return 0;
}
