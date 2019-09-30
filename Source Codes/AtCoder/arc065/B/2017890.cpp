#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 4e5 + 8;

//?????? ???+???

//?????????1?????2?????2????????????????????? Y ^_^ Y
int father[maxn], _rank[maxn];
inline void DisjointSet(int n)
{
    for(int i = 0; i <= n; i++){
        father[i] = i;
        _rank[i] = 0;
    }
}

inline int _find(int v)
{
    return father[v] = father[v] == v ? v : _find(father[v]);
    //??????????????????????????????
}

inline void _merge(int x, int y)
{
    int a = _find(x), b = _find(y);                //
    if(_rank[a] < _rank[b]){
        father[a] = b;
    }
    else{
        father[b] = a;
        if(_rank[a] == _rank[b]){
            _rank[a]++;
        }
    }
}


int father1[maxn], _rank1[maxn];
inline void DisjointSet1(int n)
{
    for(int i = 0; i <= n; i++){
        father1[i] = i;
        _rank1[i] = 0;
    }
}

inline int _find1(int v)
{
    return father1[v] = father1[v] == v ? v : _find1(father1[v]);
    //??????????????????????????????
}

inline void _merge1(int x, int y)
{
    int a = _find1(x), b = _find1(y);                //
    if(_rank1[a] < _rank1[b]){
        father1[a] = b;
    }
    else{
        father1[b] = a;
        if(_rank1[a] == _rank1[b]){
            _rank1[a]++;
        }
    }
}


map<int, vector<int>> mp1, mp2;
map<int, int> cnt;
int ans[maxn];

int main()
{
    #ifdef LOCAL
    freopen("a.txt", "r", stdin);
    //freopen("a.out", "w", stdout);
    int T = 4;
    while(T--){
    #endif // LOCAL
    ios::sync_with_stdio(false); cin.tie(0);


    int n, p, q, u, v;
    cin >> n >> p >> q;
    DisjointSet(n), DisjointSet1(n);
    while(p--){
        cin >> u >> v;
        if(_find(u) != _find(v)) _merge(_find(u), _find(v));
    }

    while(q--){
        cin >> u >> v;
        if(_find1(u) != _find1(v)) _merge1(_find1(u), _find1(v));
    }

    for(int i = 1; i <= n; i++){
        mp1[_find(i)].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        mp2[_find1(i)].push_back(i);
    }

    for(auto i = mp1.begin(); i != mp1.end(); i++){
        sort((i->second).begin(), (i->second).end());
    }
    for(auto i = mp2.begin(); i != mp2.end(); i++){
        sort((i->second).begin(), (i->second).end());
    }

    //cout << "?"<<endl;

    int i, j, a, b, pa, pb, sza, szb, l, r, mid;
    for(i = 1; i <= n; i++){
        if(ans[i] != 0) continue;
        pa = _find(i); pb = _find1(i);
        sza = mp1[pa].size(), szb = mp2[pb].size();
        cnt.clear();
        a = 0, b = 0;
        while(a < sza && b < szb){
            if(mp1[pa][a] == mp2[pb][b]){
                cnt[mp1[_find(i)][a]]++;
                a++;
                b++;
            }
            else if(mp1[pa][a] > mp2[pb][b]){
                if(b + 1== szb){
                    break;
                }
                else if(mp1[pa][a] > mp2[pb][szb - 1]){
                    break;
                }
                else{
                    l = b, r = szb;
                    b = szb - 1;
                    while(l + 1 < r){
                        mid = (l + r) >> 1;
                        if(mp1[pa][a] <= mp2[pb][mid]){
                            r = mid;
                            b = min(b, mid);
                        }
                        else l = mid;
                    }

                }
            }
            else{
                if(a + 1 == sza){
                    break;
                }
                else if(mp1[pa][sza - 1] < mp2[pb][b]){
                    break;
                }
                else{
                    l = a, r = sza;
                    a = sza - 1;
                    while(l + 1 < r){
                        mid = (l + r) >> 1;
                        if(mp1[pa][mid] >= mp2[pb][b]){
                            r = mid;
                            a = min(a, mid);
                        }
                        else l = mid;
                    }
                }
            }
        }
        sza = cnt.size();
        for(auto k = cnt.begin(); k != cnt.end(); k++){
            ans[k->first] = sza;
        }
    }

    for(i = 1; i <= n; i++){
        if(i == 1) cout << ans[i];
        else cout << " " << ans[i];
    }


    cout << endl;

    #ifdef LOCAL
    memset(ans, 0, sizeof ans);
    mp1.clear();
    mp2.clear();
    cout << endl;
    }
    #endif // LOCAL
    return 0;
}