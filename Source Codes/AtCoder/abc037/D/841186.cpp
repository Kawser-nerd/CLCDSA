//1015-
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define INT(x) int x; scanf("%d",&x)
#define INPUT(x) scanf("%d",&x)
#define REP1(x,n) for(int x = 0; x < n; x++)
#define REP2(x,s,e) for(int x = s; x <= e; x++)
#define BR printf("\n")
#define INF 2000000000
#define M 1000000007

int H,W;
int BAN[1000][1000];
int dp[1000][1000] = {};

class Point{
public:
    int h,w,v;
    Point(){}
    Point(int h,int w,int v):h(h),w(w),v(v){}
    bool operator < (const Point &p) const{return v < p.v;}
    void Print(){
        printf("%d %d %d\n",h,w,v);
    }
};

vector<Point> V;

int rec(int h,int w){
    if (dp[h][w] != 0) return dp[h][w];
    int sum = 1;
    if (BAN[h][w] < BAN[h-1][w] && h-1 >= 0) {//u
        sum = (sum + dp[h-1][w])%M;
    }
    if (BAN[h][w] < BAN[h+1][w] && h+1 <= H-1){//d
        sum = (sum + dp[h+1][w])%M;
    }
    if (BAN[h][w] < BAN[h][w-1] && w-1 >= 0){//l
        sum = (sum + dp[h][w-1])%M;
    }
    if (BAN[h][w] < BAN[h][w+1] && w+1 <= W-1){//r
        sum = (sum + dp[h][w+1])%M;
    }
    dp[h][w] = sum;
    return sum;
}

int main(){
    cin >> H >> W;
    REP1(h,H){
        REP1(w,W){
            scanf("%d",&BAN[h][w]);
            V.push_back(Point(h,w,-BAN[h][w]));
        }
    }
    sort(V.begin(),V.end());
    int sum = 0;
    int i = 0;
    REP1(h,H){
        REP1(w,W){
            sum = (sum + rec(V[i].h,V[i].w))%M;
            i++;
        }
    }
    cout << sum << endl;
    return 0;
}