#include <stdio.h>
#include <string.h>
int main() {
    FILE * fin = fopen("row.in","r");
    FILE * fout= fopen("row.out","w");
    int t,i,j,k,n,m,test,ans,a[50];
    char c[50];
    fscanf(fin,"%d",&test);
    for (t=1; t<=test; t++) {
        fscanf(fin,"%d\n",&n);
        for (i=1; i<=n; i++) {
          fgets(c,50,fin);
          a[i] = 0;
          for (j = strlen(c)-2; (j>=0)&&(c[j] == '0'); j--,a[i]++);
        } 
        for (i=n-1; i>=0; i--) {
            for (j=1; j<=n; j++)
              if (a[j]>=i) {
                     a[j] = -i; 
                     break;      
                  }
        }          
        ans = 0;
        for (i=1; i<n; i++)
          for (j=i+1; j<=n; j++)
            if (a[j]<a[i]) ans++;
        fprintf(fout,"Case #%d: %d\n",t,ans);     
    }
    return 0; 
}
