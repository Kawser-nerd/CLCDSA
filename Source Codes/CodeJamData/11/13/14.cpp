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
int desk[1<<20][3];
int cnt;

int go(vector<pip> hand, int ba, int turns){
    if (!turns)return 0;
    if (hand.empty())return 0;
//    Eo(ba);Eo(cnt);Eo(turns);Eo(hand.size());
    sort(hand.begin(),hand.end());
    int r1 = 0;
    if (hand[0].first==0){
        int st = 0;
        for (;st<hand.size()&&hand[st].first==0;st++);
        st--;
        r1 = hand[st].second;
        vector<pip> z(hand);
        z.erase(z.begin()+st,z.begin()+st+1);
        r1 += go(z,ba,turns-1);
    }
    int res = 0;
    if (hand[hand.size()-1].first==1){
        res += hand[hand.size()-1].second;
        vector<pip> z(hand);
        z.erase(z.begin()+z.size()-1);
        if (turns>1){
            int totake = 1;
            for (;totake&&ba<cnt;){
                totake--;
                int zz = desk[ba][2];
                if (zz){
                    turns += zz-1;
                    totake += desk[ba][0];
                    res += desk[ba][1];
                } else {
                    z.push_back(pip(desk[ba][0],desk[ba][1]));
                }
                ba++;
            }
        }
        res += go(z,ba,turns-1);
    }
    if (r1>res)res=r1;
    return res;
}

int solve(){
    int res = 0;
    int n ;cin >> n;
    int totake = 0;
    vector<pip> hand;
    int turns = 1;
    cnt = 0;
    for (int i = 0; i < n; i++){
        //Eo(i);
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        if (!z){
            hand.push_back(pip(x,y));
        } else {
            turns += -1+z;
            res += y;
            totake += x;
        }
    }
    int m; cin>>m;
    for (int i = 0; i < m; i++){
        //Eo(i);
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        if (totake){
            totake--;
            if (z){
                turns += -1+z;
                res += y;
                totake += x;
            } else {
                hand.push_back(pip(x,y));
            }
        } else {
            desk[cnt][0]=x;
            desk[cnt][1]=y;
            desk[cnt][2]=z;
            cnt++;
        }
    }
    //Eo("!");
    res += go(hand,0,turns);
    return res;
}

int main(){
    int t; cin >> t;
    for (int _=  0; _ < t; _++){
        printf("Case #%d: %d\n",_+1,solve());
        //        return 0;
    }
    return 0;
}
