#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
#include <tuple>
#include <deque>
#include <set>
#include <map>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long
const int INF = 1 << 29;
const ll llINF = 10000000000000000;

const int MOD = 1000000007;


#define MAX_N 200200
class UnionFindTree{
private:
    int par[MAX_N];
    int urank[MAX_N];
public:
    int init(int n);
    int find(int x);
    int unite(int x, int y);
    int same(int x, int y);
    int parnum(int x){return par[x];}
    int ranknum(int x){return urank[x];}
};

int UnionFindTree::init(int n){
    REP(i, n){
        par[i] = i;
        urank[i] = 0;
    }
    return 0;
}

int UnionFindTree::find(int x){
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
}

int UnionFindTree::unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)return 0;
    if(urank[x] < urank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(urank[x] == urank[y])urank[x] ++;
    }
    return 0;
}

int UnionFindTree::same(int x, int y){
    return find(x) == find(y);
}

int equals(){
    int N, M;
    cin >> N >> M;
    int p[100100];
    REP(i, N){
        cin >> p[i];
        p[i]--;
    }
    UnionFindTree junretu;
    junretu.init(N);
    REP(i, M){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        junretu.unite(p[x], p[y]);
    }
    int onajidayo = 0;
    
    REP(i, N){
        if(junretu.same(i, p[i])) onajidayo++;
    }
    
    return onajidayo;
}

int main(){
	printf("%d\n", equals());
}