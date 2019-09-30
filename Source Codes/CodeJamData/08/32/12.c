#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    FILE *fin  = fopen ("B-small-attempt0.in", "r");
    FILE *fout = fopen ("B-small-attempt0.txt", "w");
    
    int n,nn,l,k,m,ans,i,max;
    fscanf(fin,"%d",&n);
    for(nn=1;nn<=n;nn++){
        char a[50];
        ans=0;
        fscanf(fin,"%s",a);
        l=strlen(a);
        max=(int)pow(3,l-1);
        for(k=0;k<max;k++){
            __int64 b=0,c=a[0]-'0';
            int fu=1;
            for(m=k,i=1;i<l;m/=3,i++){
                if(m%3==0){
                    c=c*10+a[i]-'0';
                }    
                else if(m%3==1){
                    b+=c*fu;
                    fu=1;
                    c=a[i]-'0';
                }    
                else{
                    b+=c*fu;
                    fu=-1;
                    c=a[i]-'0';
                }    
            }    
            b+=c*fu;
            if(b==0||b%2==0||b%3==0||b%5==0||b%7==0)
                ans++;
        }    
        fprintf(fout,"Case #%d: %d\n",nn,ans);
    }    
    return 0;
}    
