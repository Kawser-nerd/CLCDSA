#include <cstdio>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

double fact[15];
typedef long long ll;

int kcount=0;
int keys[20000];
double prob1[20000];
map<ll, int> prob2[20000];

ll arr[4096]={1};
void dfs(int at, int key, int left, double res){
    if(at == 9){
        if(left)
            return;
        keys[kcount]=key;
        prob1[kcount]=res;
        for(int j=0; j<4096; j++)
            prob2[kcount][arr[j]]++;
        kcount++;
    }else{
        int cc=1<<(12-left);
        for(int i=0; i<=left; i++){
            dfs(at+1, 16*key+i, left-i, res/fact[i]);
            if(i < left){
                for(int j=0; j<cc; j++){
                    arr[j+cc]=at*arr[j];
                }
                cc*=2;
            }
        }
    }
}

int main()
{
    fact[0]=1;
    for(int i=1; i<15; i++)
        fact[i]=i*fact[i-1];
    dfs(2, 0, 12, 1);
    fprintf(stderr, "Ready\n");

    int T, R, N, M, K;
    scanf("%d%d%d%d%d", &T, &R, &N, &M, &K);
    printf("Case #1:\n");
    while(R--){
        if(!(R%100))
            fprintf(stderr, "Cases left: %d\n", R);
        ll v[12];
        for(int i=0; i<K; i++)
            scanf("%lld", v+i);
        int bestkey=0;
        double bestprob=0;
        for(int ki=0; ki<kcount; ki++){
            int key=keys[ki];
            double prob = prob1[ki];
            for(int i=0; i<K; i++){
                auto it2=prob2[ki].find(v[i]);
                if(it2==prob2[ki].end()){
                    prob=0; break;
                }
                prob*=it2->second;
            }
            if(prob > bestprob){
                bestkey=key;
                bestprob=prob;
            }
        }
        assert(bestprob!=0);
        for(int i=8; i>=2; i--){
            int c=bestkey%16;
            bestkey/=16;
            while(c--)
                printf("%d", i);
        }
        putchar('\n');
    }
}
