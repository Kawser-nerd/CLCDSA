#include <stdio.h>
int x[50],y[50],r[50];
double Dist(int i , int j){
       return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}

int main() {
    FILE * fin = fopen("plant.in","r");
    FILE * fout= fopen("plant.out","w");
    int i,j,k,n,m,test,t;
    double ans,tt;
    fscanf(fin,"%d",&test);
    for (t=1; t<=test; t++) {
        fscanf(fin,"%d",&n);
        for (i=1; i<=n; i++) {
            fscanf(fin,"%d %d %d",&x[i],&y[i],&r[i]);
        }
        ans = 10000000000;
        if (n==1) fprintf(fout,"Case #%d: %0.8f\n",t,r[1]);
        if (n==2) {
            if (r[1]<r[2]) ans = r[2];
               else ans = r[1];      
            fprintf(fout,"Case #%d: %0.8f\n",t,ans);   
                  }
        if (n<=2) continue;
        for (i=1; i<n; i++)
          for (j=i+1; j<=n; j++) {
            tt = (Dist(i,j)+ r[i] + r[j]) /2;
            for (k=1; k<=n; k++)
              if ((k!=i)&&(k!=j)&&(r[k]>tt)) tt=r[k];
            if (tt<ans) ans = tt;    
          }
        fprintf(fout,"Case #%d: %0.8f\n",t,ans);  
    } 
    return 0;
}
