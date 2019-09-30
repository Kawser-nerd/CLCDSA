#include <stdio.h>
int n,map[110][110],link[110],vy[110];

int Find(int x){
    int i,j,k;
    for (i=1; i<=n; i++)
      if ((map[x][i])&&(! vy[i])) {
             vy[i] = 1; k=link[i]; link[i]=x;
             if ((k==0)||(Find(k))) return 1;
             link[i] = k;             
         }
    return 0;     
} 

int main() {
    FILE * fin = fopen("chart.in","r");
    FILE * fout= fopen("chart.out","w");
    int ans,i,j,k,m,test,t,a[110][30];
    fscanf(fin,"%d",&test);
    for (t=1; t<=test; t++) {
        fscanf(fin,"%d %d",&n,&m);
        for (i=1; i<=n; i++)
          for (j=1; j<=m; j++)
            fscanf(fin,"%d",&a[i][j]);
        memset(map,0,sizeof(map)); 
        memset(link,0,sizeof(link));   
        for (i=1; i<=n; i++)
          for (j=1; j<=n; j++) {
              for (k=1; (k<=m)&&(a[i][k]>a[j][k]); k++);
              if (k>m) map[i][j] = 1;
          }    
        ans = n;  
        for (i=1; i<=n; i++) {
            memset(vy,0,sizeof(vy));
            if (Find(i))
               ans--;  
        }  
        fprintf(fout,"Case #%d: %d\n",t,ans);
    }
    return 0;
}
