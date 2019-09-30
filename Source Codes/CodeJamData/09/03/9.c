#include <stdio.h>
void     work(){
         long len,i,j;
         long ans=0;
         long f[1000][30]={0};
         char s[1000];
         char x[25]=" welcome to code jam";
         for(len=1;len<=2000;len++){
             scanf("%c",&s[len]);
             if(s[len]=='\n') {len--;break;}
         }
         f[0][0]=1;
         for(i=1;i<=len;i++){
          for(j=0;j<=19;j++){
              if(j>i) continue;
              if(i-1>=j) f[i][j] = f[i-1][j];
              if(j>0&&x[j]==s[i])
               f[i][j] += f[i-1][j-1];
              f[i][j] %= 10000;
          }
         }
/*          for(i=1;i<=len;i++){
          ans+=f[i][19];
          ans%=10000;}*/
         printf("%04ld\n",f[len][19]);
}
int      main(){               
         long t,i;
         freopen("C-large.in","r",stdin);
         freopen("C-large.out","w",stdout);
         scanf("%ld\n",&t);
         for(t,i=1;t;t--,i++){
            printf("Case #%ld: ",i);
            work();
         }
         return 0;
}
