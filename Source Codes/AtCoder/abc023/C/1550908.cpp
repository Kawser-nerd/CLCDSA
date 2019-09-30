#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int R, C, K, N;
int width[100001] = {0};
int height[100001] = {0};
int c[100001] = {0};
int r[100001] = {0};

vector<P> v;

int main(){
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> R >> C >> K >> N;
    for(int i = 0; i < N; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        width[x]++;
        height[y]++;
        v.push_back(P(x, y));
    }
    
    for(int i = 1; i <= R; ++i){
        c[width[i]]++;
    }

    for(int i = 1; i <= C; ++i){
        r[height[i]]++;
    }

    for(int i = 0; i <= K; ++i){
        sum1 += c[i] * r[K-i];
    }

    for(int i = 0; i < N; ++i){
        if(width[v[i].first] + height[v[i].second] == K) sum2++;
        if(width[v[i].first] + height[v[i].second] == K+1) sum3++;
    }

    cout << sum1 - sum2 + sum3 << endl;

    return 0;  
}