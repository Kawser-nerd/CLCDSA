#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef long long int llint;

#define PI 3.14159265358979323846264338327950288
#define INF 0x7f7f7f7f
#define EPS 0.000000000001

#define TAM 110

int foi[TAM][TAM][TAM];


int main(){
    int i,j,k;    
    int cont;
    int teste,nteste;
    llint n,a,b,c,d,x1,y1,m;
    llint x[TAM],y[TAM];
    scanf("%d",&nteste);
    for(teste=1;teste<=nteste;teste++){
        memset(foi,0,sizeof(foi));                               
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&a,&b,&c,&d,&x1,&y1,&m);
        x[0]=x1;y[0]=y1;        
        for(i=1;i<n;i++){   
           x[i]=(a*x[i-1]+b)%m;
           y[i]=(c*y[i-1]+d)%m;
        }
        cont=0;
        for(i=0;i<n;i++)
         for(j=i+1;j<n;j++)
          for(k=j+1;k<n;k++)
            if(!foi[i][j][k]){
              if(!((x[i]+x[j]+x[k])%3) && !((y[i]+y[j]+y[k])%3))
                cont++;
              foi[i][j][k]=foi[i][k][j]=foi[j][k][i]=foi[j][i][k]=foi[k][i][j]=foi[k][j][i]=1;
            }
         printf("Case #%d: %d\n",teste,cont);                                            
    }
    return 0;
}
