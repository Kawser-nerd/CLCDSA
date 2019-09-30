#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int64_t> V(3*N);
    for(auto &a:V) cin>>a;
    vector<int64_t> head_sum(N+1),tail_sum(N+1);
    priority_queue<int64_t, vector<int64_t>, greater<int64_t> > head_queue;
    for(int i=0;i<N;i++){
        head_sum[0]+=V[i];
        head_queue.push(V[i]);
    }
    for(int i=0;i<N;i++){
        head_queue.push(V[i+N]);
        head_sum[i+1]=head_sum[i]+V[i+N]-head_queue.top();
        head_queue.pop();
    }
    priority_queue<int64_t> tail_queue;
    for(int i=0;i<N;i++){
        tail_sum[0]+=V[3*N-1-i];
        tail_queue.push(V[3*N-1-i]);
    }
    for(int i=0;i<N;i++){
        tail_queue.push(V[2*N-1-i]);
        tail_sum[i+1]=tail_sum[i]+V[2*N-1-i]-tail_queue.top();
        tail_queue.pop();
    }
    int64_t ans=-1e17;
    for(int i=0;i<=N;i++){
        ans=max(ans,head_sum[i]-tail_sum[N-i]);
    }
    cout<<ans<<endl;

    return 0;
}