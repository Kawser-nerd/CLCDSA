#include<stdio.h>
int lawn[100][100];
int main() {
    int t,i,j,k,n,m,c=0,f1,f2,ans;
    scanf("%d",&t);
    while(t--) {
               scanf("%d%d",&n,&m);
               for(i=0;i<n;i++)
                               for(j=0;j<m;j++)
                                               scanf("%d",&lawn[i][j]);
               ans=1;
               for(i=0;i<n;i++)
                               for(j=0;j<m;j++) {
                                                f1=f2=0;
                                                //Row check
                                                for(k=0;k<m;k++)
                                                                if(lawn[i][k]>lawn[i][j]) {
                                                                                          f1=1;
                                                                                          break;
                                                                }
                                                //Column check
                                                for(k=0;k<n;k++)
                                                                if(lawn[k][j]>lawn[i][j]) {
                                                                                          f2=1;
                                                                                          break;
                                                                }
                                                if(f1&f2) {
                                                          ans=0;
                                                          goto end;
                                                }
                               }
               end:
                   printf("Case #%d: %s\n",++c,ans?"YES":"NO");
    }
    return 0;
}
