//#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define Eo(x) {cerr<< #x << " = " << (x) << endl;}

typedef double real;
typedef long long int64;
const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-6;
typedef pair<int,int> pip;

string d[15000];
char was[12];
int n;
map<string,int> num;
string t;

pair<int,string> go(int l, const vector<string>& can, int p){
    if (can.size()<=0) return pair<int,string>(0,"");
    if (can.size()<=1) return pair<int,string>(0,can[0]);
    assert(can.size()>1);
    map<string,vector<string> > dif;
    pair<int,string> res(-1,"");
    for(;;){
        char x = t[p];
        int has = 0;
        dif.clear();
        for(vector<string>::const_iterator it = can.begin(); it != can.end(); ++it){
            const string& s = *it;
            string z(s);
            for (int j = 0; j < s.size(); j++){
                if (s[j]==x){
                    z[j]=x;
                    has=1;
                } else {
                    z[j] = ' ';
                }
            }
            dif[z].push_back(s);
        }
        if (!has){
            p++;
            continue;
        }
        for (map<string,vector<string> >::iterator it = dif.begin(); it != dif.end(); ++it){
            char h = 0;
            const string& s = it->first;
            for (int i = 0; i < s.size(); i++)
                if (s[i] != ' '){
                    h = 1;
                    break;
                }
            pair<int,string> q = go(l,it->second,p+1);
            if (!h){
                q.first++;
            }
            if (q.first>res.first){
                res=q;
            } else if (q.first==res.first){
                if (num[q.second]<num[res.second]){
                    res = q;
                }
            }
        }
        break;
    }
    return res;
}

string solve(){
    int mx = -1;
    string best;
    for (int l = 1; l <= 10; l++){
        vector<string> can;
        for (int i = 0; i < n; i++) if (d[i].size()==l){
            can.push_back(d[i]);
        }
        if (can.empty())continue;
        pair<int,string> z = go(l,can,0);
        if (z.first<mx)continue;
        if (z.first>mx){
            mx = z.first;
            best = z.second;
            continue;
        }
        if (num[z.second]<num[best]){
            best = z.second;
        }
    }
    return best;
}

int main(){
    int T; cin >> T;
    for (int _ = 0; _ < T; _++){
        int m; cin >> n >> m;
        num.clear();
        for (int i = 0; i < n; i++){
            cin >> d[i];
            num[d[i]] = i;
        }
        printf("Case #%d:",_+1);
        for (int i = 0; i < m; i++){
            cin >> t;
            printf(" %s",solve().c_str());
        }
        puts("");
    }
    return 0;
}
