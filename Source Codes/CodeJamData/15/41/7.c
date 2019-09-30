#include <stdio.h>

long map[110][110],rr[110],cr[110],r,c;

long deal(long x,long y,long k){
    long xx,yy;
    xx=x;
    yy=y;
    if (k==1)
        xx--;
    if (k==2)
        xx++;
    if (k==3)
        yy--;
    if (k==4)
        yy++;
    if (xx<0||xx>=r||yy<0||yy>=c)
        return 1;
    else if (map[xx][yy]>0)
        return 0;
    else
        return deal(xx,yy,k);
}

int main() {
    long i,j,t,tt,ans;
    char x;
    freopen("A-large.in.txt", "r", stdin);
    freopen("A-large.out.txt", "w", stdout);
    
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%ld",&r,&c);
        for (i=0;i<110;i++){
            rr[i]=0;
            cr[i]=0;
        }
        for (i=0;i<r;i++)
            for (j=0;j<c;j++){
                scanf("%c",&x);
                while (x!='.'&&x!='^'&&x!='<'&&x!='>'&&x!='v')
                    scanf("%c",&x);
                if (x=='.')
                    map[i][j]=0;
                if (x=='^')
                    map[i][j]=1;
                if (x=='v')
                    map[i][j]=2;
                if (x=='<')
                    map[i][j]=3;
                if (x=='>')
                    map[i][j]=4;
                if (map[i][j]>0){
                    rr[i]++;
                    cr[j]++;
                }
            }
        ans=0;
        for (i=0;i<r&&ans>=0;i++)
            for (j=0;j<c&&ans>=0;j++)
                if (map[i][j]>0){
                    if (rr[i]==1&&cr[j]==1){
                        ans=-1;
                        break;
                    }
                    ans+=deal(i,j,map[i][j]);
                }
        printf("Case #%ld: ",tt);
        if (ans==-1){
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%ld\n",ans);
        }
    }
    return 0;
}
