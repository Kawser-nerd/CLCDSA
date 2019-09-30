#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    if(mx <= 0){
        cout << mx << endl;
        int id = max_element(a.begin(), a.end()) - a.begin() + 1;
        cout << N - 1 << endl;
        for(int i=N; i>id; i--)
            cout << i << endl;
        for(int i=1; i<id; i++)
            cout << 1 << endl;
        return 0;
    }

    long long w = 0, b = 0;
    for(int i=0; i<N; i+=2)
        if(a[i] > 0)
            w += a[i];
    for(int i=1; i<N; i+=2)
        if(a[i] > 0)
            b += a[i];

    long long ans = max(w, b);
    cout << ans << endl;

    vector<int> dl;
    if(ans == w){
        for(int i=0; i<N; i+=2)
            if(a[i] < 0)
                dl.push_back(i);
    }else{
        for(int i=1; i<N; i+=2)
            if(a[i] < 0)
                dl.push_back(i);
    }
    int M = N - 2*dl.size();
    bool flg = false;
    if(!dl.empty() && dl[0] == 0){
        M++;
        flg = true;
    }
    if(!dl.empty() && dl.back() == N-1) M++;

    vector<int> dl2;
    if( (!flg && ans == w) || (flg && ans == b)){
        for(int i=1; i<M; i+=2)
            dl2.push_back(i);
    }else{
        for(int i=0; i<M; i+=2)
            dl2.push_back(i);
    }

    cout << dl.size() + dl2.size() << endl;
    reverse(dl.begin(), dl.end());
    reverse(dl2.begin(), dl2.end());
    for(int x : dl)
        cout << x+1 << endl;
    for(int x : dl2)
        cout << x+1 << endl;

    return 0;
}