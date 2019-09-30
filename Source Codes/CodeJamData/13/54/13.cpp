#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>

double nCr[205][205];
long double padd[205][205];
long double pskip[205][205];

double solve(const char *buf){
    double prob[201][201]={1};
    double cost[201][201]={};
    int N=strlen(buf);
    int M=0;
    for(int i=0; i<N; i++)
        if(buf[i]=='.')
            M++;
    for(int it=0; it<N; it++){
        double nextprob[201][201]={}, nextcost[201][201]={};

        for(int i=0; i<=M; i++)
            for(int j=0; j<=M; j++)
            {
                if(prob[i][j]==0)
                    continue;
                double osum=0;
                for(int k=i; k<=M; k++)
                {
                    int add=k-i;
                    int skip=M-k;
                    int unplaced=add+j;
                    assert(add>=0 && skip>=0);
                    double odds = padd[N-it][add] * pskip[N-it][skip] * nCr[M-i][add];
                    osum+=odds;
                    assert(0<=unplaced && unplaced<=M);
                    int c=0;
                    if(buf[it]=='.')
                    {
                        if(unplaced==0){
                            c=it;
                        }
                        else
                        {
                            unplaced--;
                            c=unplaced;
                        }
                    }
                    else
                    {
                        c=unplaced;
                    }
                    nextprob[k][unplaced]+=prob[i][j]*odds;
                    nextcost[k][unplaced]+=odds*(cost[i][j]+prob[i][j]*c);
                }
                assert(.99999<=osum && osum<=1.00001);
            }

        for(int i=0; i<=M; i++)
            for(int j=0; j<=M; j++)
            {
                prob[i][j]=nextprob[i][j];
                cost[i][j]=nextcost[i][j];
            }
        /*
        if(N==3)
        {
            for(int i=0; i<=M; i++){
                for(int j=0; j<=M; j++)
                {
                    printf("%f ", prob[i][j]);
                }
                puts("");
            }
            puts("");
            for(int i=0; i<=M; i++){
                for(int j=0; j<=M; j++)
                {
                    printf("%f ", cost[i][j]);
                }
                puts("");
            }
            puts("");
            puts("");
        }
        */
    }
    double ret=0;
    for(int i=0; i<=M; i++)
        ret+=cost[M][i];
    return M*N-ret;
}

int main(){
    for(int i=0; i<205; i++){
        for(int j=0; j<=i; j++)
        {
            if(i==0 || i==j)
                nCr[i][j]=1;
            else
                nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
        }
        for(int j=0; j<205; j++)
        {
            padd[i][j]=pow(1.0/i, j);
            pskip[i][j]=pow(1-1.0/i, j);
        }
    }
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        char buf[205];
        scanf(" %s", buf);
        printf("Case #%d: %.9f\n", t, solve(buf));
    }
}
