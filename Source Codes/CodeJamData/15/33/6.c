#include<stdio.h>

int d;
int coin[100];
int newcoin[100];
int possible[100];

void gen_possible(int x,int sum) {
    if(x==d) {
        possible[sum]=1;
        return;
    }
    gen_possible(x+1,sum);
    gen_possible(x+1,sum+coin[x]);
}

int main() {
    int t,tt;
    FILE* fin = fopen("C-small-attempt1.in","r");
    FILE* fout = fopen("out.txt","w");
    fscanf(fin,"%d",&t);

    int c,v,i,j,fail,ans,max;

    for(tt=1;tt<=t;tt++) {
        fail=0;
        ans=0;
        fscanf(fin,"%d %d %d",&c,&d,&v);
        for(i=0;i<=v;i++)
            possible[i]=0;
        for(i=0;i<d;i++)
            fscanf(fin,"%d",&coin[i]);
        gen_possible(0,0);
        for(i=1;i<=v;i++) {
            if(!possible[i]) {
                fail=1;
                break;
            }
        }
        while(fail) {
            ans++;
            coin[d]=i;
            d++;
            for(i=0;i<=v;i++)
                possible[i]=0;
            gen_possible(0,0);
            fail=0;
            for(i=1;i<=v;i++) {
                if(!possible[i]) {
                    fail=1;
                    break;
                }
            }
        }
        fprintf(fout,"Case #%d: %d\n",tt,ans);
    }
    fclose(fin);
    fclose(fout);
}
