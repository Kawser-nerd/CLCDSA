#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#define INC(i, a, b) for(int i = a; i < b; ++i)
#define DEC(i, a, b) for(int i = a; i > b; --i)
#define REP(i, n) INC(i, 0, n)

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

using namespace std;

void TFprint(bool b, std::string T, std::string F){
    if(b){
        std::cout << T << std::endl;
    }else{
        std::cout << F << std::endl;
    }
}

typedef struct{
    ll amount;
    double price;
    ll p;
}tea;

bool comp(const tea& lt, const tea& rt)
{
  return lt.price < rt.price;
}

int main(){
    tea q, h, s, d;

    q.amount = -2;
    h.amount = -1;
    s.amount = 0;
    d.amount = 1;

    cin >> q.p, q.price = q.p * 4.0;
    cin >> h.p, h.price = h.p * 2.0;
    cin >> s.p, s.price = s.p * 1.0;
    cin >> d.p, d.price = d.p * 0.5;

    ll n; cin >> n;

    vector<tea> t;
    t.push_back(q), t.push_back(h), t.push_back(s), t.push_back(d);
    sort(t.begin(), t.end(), comp);

    ll ans = 0;

    REP(i, 4){

        if(n == 0){
            break;
        }

        ll buy;
        if(t[i].amount >= 0){
            buy = n >> t[i].amount;
            ans += buy * t[i].p;
            n -= (1 << t[i].amount) * buy;
        }
        else{
            buy = n << (-t[i].amount);
            ans += buy * t[i].p;
            n = 0;
        }

    }
    cout << ans <<endl;
    return 0;
}