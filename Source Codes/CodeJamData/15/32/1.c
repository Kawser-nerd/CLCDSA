#include <stdio.h>

long f[200];
double p[27],ave[110][110],prob[110][110],max[110][110];
char s1[200],s2[200];


int main() {
    long t,tt,i,j,k,l,s,t1,t2,x,y;
    double ans,av,ma;
    char c;
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%ld%ld",&k,&l,&s);
        scanf("%s",s1);
        scanf("%s",s2+1);
        s2[0]='#';
        for (i=0;i<26;i++)
            p[i]=0;
        for (i=0;i<k;i++){
            p[s1[i]-'A']+=1.0/k;
        }
        f[0]=-1;
        f[1]=0;
        for (i=2;i<=l;i++){
            for (j=f[i-1];j!=-1&&s2[j+1]!=s2[i];j=f[j]);
            f[i]=j+1;
        }
        for (i=0;i<=s;i++){
            for (j=0;j<=l;j++){
                ave[i][j]=-1;
                max[i][j]=-1;
                prob[i][j]=0;
            }
        }
        ave[0][0]=0;
        max[0][0]=0;
        prob[0][0]=1;
        for (i=0;i<s;i++){
            for (j=0;j<l;j++){
                if (ave[i][j]>=0){
                    for (x=0;x<26;x++){
                        if (p[x]>0){
                            c='A'+x;
                            for (y=j;y>=0&&c!=s2[y+1];y=f[y]);
                            y++;
                            if (y<l){
                                if (ave[i+1][y]<0)
                                    ave[i+1][y]=0;
                                prob[i+1][y]+=prob[i][j]*p[x];
                                ave[i+1][y]+=ave[i][j]*p[x];
                                if (max[i][j]>max[i+1][y])
                                    max[i+1][y]=max[i][j];
                            }
                            else {
                                y=f[y];
                                if (ave[i+1][y]<0)
                                    ave[i+1][y]=0;
                                ave[i+1][y]+=(1*prob[i][j]+ave[i][j])*p[x];
                                prob[i+1][y]+=prob[i][j]*p[x];
                                if (max[i][j]+1>max[i+1][y])
                                    max[i+1][y]=max[i][j]+1;
                            }
                        }
                    }
                }
            }
        }
        for (i=0,ma=0,av=0;i<l;i++){
            if (ave[s][i]>=0){
                av+=ave[s][i];
                if (max[s][i]>ma)
                    ma=max[s][i];
            }
        }
        printf("Case #%ld: %0.6lf\n",tt,ma-av);
    }
    return 0;
}
