#include<stdio.h>

char key[10];
char pattern[10];
char ss[10];
int banana[10];
int k,l,s,max,c;

int check_repeat() {
    int i,j,ans=0;
    for(i=0;i<=s-l;i++) {
        for(j=0;j<l;j++) {
            if(pattern[j]!=ss[i+j])
                break;
        }
        if(j==l)
            ans++;
    }
    return ans;
}

void gen(int x) {
    int b;
    if(x==s) {
        c++;
        b = check_repeat();
        banana[b]++;
        if(b>max)
            max=b;
        return;
    }
    for(b=0;b<k;b++) {
        ss[x]=key[b];
        gen(x+1);
    }
}

int main() {
    int t,tt;
    FILE* fin=fopen("B-small-attempt0.in","r");
    FILE* fout=fopen("out.txt","w");
    fscanf(fin,"%d",&t);
    int i;
    double ans;
    for(tt=1;tt<=t;tt++) {
        fscanf(fin,"%d %d %d %s %s",&k,&l,&s,key,pattern);
        max=0;
        c=0;
        for(i=0;i<10;i++)
            banana[i]=0;
        gen(0);
        ans = (double)max;
        for(i=0;i<10;i++)
            printf("%d ",banana[i]);
        printf("\n\n");
        for(i=1;i<10;i++)
            ans-=((double)banana[i]/(double)c)*(double)i;
        fprintf(fout,"Case #%d: %lf\n",tt,ans);
    }
}
