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
typedef pair<ll, ll> pint;

int twocolors(){
    map<string, int> card;
    int N, M;
    cin >> N;
    REP(i, N){
        string s;
        cin >> s;
        card[s]++;
    }
    cin >> M;
    REP(i, M){
        string s;
        cin >> s;
        card[s]--;
    }
    map<string, int>::iterator ite;
    int saidai = 0;
    for(ite = card.begin(); ite != card.end(); ++ite){
        saidai = max(saidai, ite->second);
    }
    return saidai;
}

int kagamimochi(){
    set<int> mochi;
    int N;
    cin >> N;
    REP(i, N){
        int a;
        cin >> a;
        mochi.insert(a);
    }
    return mochi.size();
}

ll threeNumbers(){
    
    int N;
    cin >> N;
    priority_queue<int> a1;
    priority_queue<int> a2;
    ll akmade[100010] = {0};
    ll akkara[100010] = {0};
    int a[300010];
    REP(i, 3 * N){
        cin >> a[i];
    }
    ll score = -llINF;
    REP(i, N){
        a1.push(-a[i]);
        a2.push(a[3 * N - i -1]);
        akmade[0] += a[i];
        akkara[0] += a[3 * N - i - 1];
    }
    REP(i, N){
        akmade[i + 1] = akmade[i] + a[i + N];
        a1.push(-a[i + N]);
        akmade[i + 1] += a1.top();
        a1.pop();
    }
    
    REP(i, N){
        akkara[i + 1] = akkara[i] + a[2 * N - i - 1];
        a2.push(a[2 * N - i - 1]);
        akkara[i + 1] -= a2.top();
        a2.pop();
    }
    
    REP(i, N + 1){
        if(score < akmade[i] - akkara[N - i])score = akmade[i] - akkara[N - i];
    }
    return score;
}

class factorypque
{
private:
    ll heap[100010][2];
    int sz = 0;
    
public:
    void push(ll a, ll b);
    pint pop();
};

void factorypque::push(ll a, ll b){
    int i = sz;
    sz ++;
    while(i > 0){
        
        int p = (i - 1) / 2;
        if(heap[p][0] <= a)break;
        heap[i][0] = heap[p][0];
        heap[i][1] = heap[p][1];
        i = p;
    }
    heap[i][0] = a;
    heap[i][1] = b;
}

pint factorypque::pop(){
    ll ret1 = heap[0][0];
    ll ret2 = heap[0][1];
    ll x = heap[sz - 1][0];
    ll y = heap[sz - 1][1];
    int i = 0;
    while(i * 2 + 1 < sz){
        int a = i  * 2 + 1, b = i * 2 + 2;
        if(b < sz && heap[b][0] < heap[a][0]){
            a = b;
        }
        if(heap[a][0] >= x)break;
        heap[i][0] = heap[a][0];
        heap[i][1] = heap[a][1];
        i = a;
    }
    
    
    heap[i][0] = x;
    heap[i][1] = y;
    sz --;
    
    return pint(ret1, ret2);
}

ll factory(){
    int N, K;
    cin >> N >> K;
    factorypque kikaijikan;
    
    REP(i, N){
        int a,b;
        cin >> a >> b;
        kikaijikan.push(a,b);
    }
    ll saishoujikan = 0;
    REP(i, K){
        
        pint tuginokikai = kikaijikan.pop();
        saishoujikan += tuginokikai.first;
        kikaijikan.push(tuginokikai.first + tuginokikai.second, tuginokikai.second);
    }
    
    return saishoujikan;
}


int main(){
    printf("%d\n",twocolors());
}