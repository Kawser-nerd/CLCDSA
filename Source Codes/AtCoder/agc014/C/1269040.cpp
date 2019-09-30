#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<unordered_set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
template <class... T> void printArr(T&&...){ }
#endif

struct Elem{
    int y, x, blocks;
    bool stay = false;
    bool operator < (const Elem& e) const{
        // return y != e.y ? y < e.y : x != e.x ? x < e.x : blocks < e.blocks;
        return y != e.y ? y < e.y : x < e.x;
    }
};

char as[801][801];
int visited[801][801];
int main(){
    int h, w, k;
    cin >> h >> w >> k;
    set<Elem> q;
    queue<Elem> qu;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> as[i][j];
            if(as[i][j] == 'S'){
                as[i][j] = '.';
                q.insert({i, j, 0});
                qu.push({i, j, 0});
            }
        }
    }
    int minlen = M;
    while(qu.size()){
        auto e = qu.front(); qu.pop();
        if(e.y < 0 || h <= e.y || e.x < 0 || w <= e.x || as[e.y][e.x] == '#'){ continue; }
        as[e.y][e.x] = '#';
        if(e.blocks > k){ break; }
        minlen = min({minlen, w - 1 - e.x, e.x, h - 1 - e.y, e.y});
        qu.push({e.y + 1, e.x, e.blocks + 1});
        qu.push({e.y - 1, e.x, e.blocks + 1});
        qu.push({e.y, e.x + 1, e.blocks + 1});
        qu.push({e.y, e.x - 1, e.blocks + 1});
    }
    cout << 1 + (minlen + k - 1) / k << '\n';
    return 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            visited[i][j] = M;
        }
    }
    for(int i=0;i<500;i++){
        prints(i);
        prints(q.size());
        auto q2 = q;
        for(int j=0;j<k;j++){
            set<Elem> next;
            for(const Elem& e : q){
                if(visited[e.y][e.x] <= e.blocks){
                // if(visited[e.y][e.x] <= e.blocks && e.stay == false){}
                    continue;
                }
                visited[e.y][e.x] = e.blocks;
                auto f = [&](int y, int x, int b){
                    int nb = b + (as[y][x] == '#');
                    if(nb <= k * i){
                        // prints(y, x, b);
                        if(y == 0 || y == h - 1 || x == 0 || x == w - 1){
                            cout << i + 1 << '\n';
                            exit(0);
                        }
                        if(visited[y][x] > nb){
                            next.insert({y, x, nb});
                        }
                    }
                };
                f(e.y + 1, e.x, e.blocks);
                f(e.y - 1, e.x, e.blocks);
                f(e.y, e.x + 1, e.blocks);
                f(e.y, e.x - 1, e.blocks);
            }
            next.swap(q);
        }
        // for(const Elem& e : q2){
        //     if(e.stay == false){
        //         q.insert({e.y, e.x, e.blocks, true});
        //     }
        // }
    }
    return 0;
}