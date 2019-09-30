#include<stdio.h>

int main() {
    int t,tt,r,c,w,ans;
    FILE* fin = fopen("A-large.in","r");
    FILE* fout = fopen("out.txt","w");
    fscanf(fin,"%d",&t);
    for(tt=1;tt<=t;tt++) {
        fscanf(fin,"%d %d %d",&r,&c,&w);
        ans=r*(c/w);
        if(c%w==0)
            ans+=(w-1);
        else
            ans+=w;
        fprintf(fout,"Case #%d: %d\n",tt,ans);
    }
    fclose(fin);
    fclose(fout);
}
