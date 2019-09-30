#include <stdio.h>
#include <string.h>
double   c[101][101]={0};
double   f[2001][41]={0};
int      main(){
         long T;
         long i,j,k;
         long time;
         long N,M;
         double ans;
         freopen("C-large.in","r",stdin);
         freopen("C-large.out","w",stdout);
         for(i=0;i<=100;i++){
              c[i][0]=1;
              for(j=1;j<=100;j++)
               c[i][j]=c[i-1][j]+c[i-1][j-1];
         }
         scanf("%ld",&T);
         for(T,k=1;T;T--,k++){
          scanf("%ld%ld",&N,&M);
          memset(f,0,sizeof(f));
          ans=0;
          f[0][0]=1;
          for(time=0;time<2000;time++){
             for(i=0;i<N;i++)
              for(j=0;j<=M;j++)
               if(j<=i&&(M-j)<=(N-i))
                f[time+1][i+M-j]+=f[time][i]*c[i][j]*c[N-i][M-j]/c[N][M];
          }
          ans=0;
          for(i=0;i<2000;i++)
            ans+=f[i][N]*(double)i;
          printf("Case #%ld: %.7lf\n",k,ans);
         }
         return 0;
}
