#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<deque>

#define INF (1e9)

using namespace std;

typedef long long int Int;

int main(void) {
    int K;
    cin>>K;
    vector<int> cost(K,INF);
    cost[1] = 1;
    deque<int> q;
    q.push_front(1);
    while(!q.empty()) {
        int x = q.front();q.pop_front();
        int y = (x+1) % K;
        if(cost[y] > cost[x]+1) {
            cost[y] = cost[x]+1;
            q.push_back(y);
        }
        int z = (x*10)%K;
        if(cost[z] > cost[x]) {
            cost[z] = cost[x];
            q.push_front(z);
        }
    }

    cout<<cost[0]<<endl;

    return 0;
}