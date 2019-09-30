#include <stdio.h>
#include <string.h>
int c[600],t[600],ans[600];

void Add(int a[600],int b[600]) {
     int i,l;
     l = a[0]; 
     if (b[0]>a[0]) l=b[0];
     for (i=1; i<=l; i++) {
         a[i] += b[i];
         if (a[i]>9)
            a[i]-=10 , a[i+1]++;
     }     
     if (a[l+1]!=0) l++;
     a[0] = l;
}

void Muti(int a[600],int b[600],int k) {
     int i,l = b[0],m=0;
     int c[600];
     memset(c,0,sizeof(c));
     for (i=1; i<=l; i++) {
         m += b[i]*k;
         c[i] = m % 10;
         m = m/ 10;
     }       
     while (m>0) {
         l++;  
         c[l] = m% 10;
         m = m / 10;   
     }
     for (i=1; i<=l; i++)
       a[i] = c[i];
     a[0] = l;  
}

int main() {
    FILE * fin = fopen("base1.in","r");
    FILE * fout= fopen("base1.out","w");
    int l,i,j,k,tt,test,n;
    char a[80];
    int b[600];
    fscanf(fin,"%d\n",&test);
    for (tt=1; tt<=test; tt++) {
        fgets(a,70,fin);
        for (i=0; i<600; i++)
          b[i] = -1;
        n = 0; 
        l = strlen(a)-1;
        b[a[0]]=1;
        for (i=1; i<l; i++) 
          if (b[a[i]] == -1) {
                 b[a[i]] = n;
                 n++;
                 if (n == 1) n++;
              }
        if (n==0) n=2;  
        memset(t,0,sizeof(t));
        memset(ans,0,sizeof(ans));
        t[0] = t[1] = ans[0] = 1;    
        for (i=l-1; i>=0; i--) {             
          if (b[a[i]]>0)
             Muti(c,t,b[a[i]]) , Add(ans,c);
          if (i>0) Muti(t,t,n);        
        }  
        fprintf(fout,"Case #%d: ",tt);
        for (i=ans[0]; i>0; i--)
          fprintf(fout,"%d",ans[i]);
        fprintf(fout,"\n");  
    }
    return 0;
} 
