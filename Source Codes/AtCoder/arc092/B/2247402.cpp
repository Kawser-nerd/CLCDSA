#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];

    vector<int> c[29];
    for(int i=0; i<29; i++){
        c[i].resize(N);
        for(int j=0; j<N; j++) c[i][j] = b[j] % (1<<(i+1));
        sort(c[i].begin(), c[i].end());
    }

    vector<int> cnt(29, 0);
    for(int i=0; i<29; i++){
        for(int j=0; j<N; j++){
            int d = a[j] % (1<<(i+1));
            cnt[i] += lower_bound(c[i].begin(), c[i].end(), (1<<(i+1))-d)
                    - lower_bound(c[i].begin(), c[i].end(), (1<<i)-d);
            cnt[i] += lower_bound(c[i].begin(), c[i].end(), (1<<(i+2))-d)
                    - lower_bound(c[i].begin(), c[i].end(), (1<<i) + (1<<(i+1)) - d);
            //if( !(d & (1<<i)) )
            //    cnt[i] += c[i].end()
            //            - lower_bound(c[i].begin(), c[i].end(), (1<<i) - d);
            //else
            //    cnt[i] += upper_bound(c[i].begin(), c[i].end(), (1<<i) - d) - c[i].begin();
        }
        //cerr << cnt[i] << " ";
    }
    //cerr << endl;

    int ans = 0;
    for(int i=0; i<29; i++)
        if(cnt[i] % 2)
            ans |= 1<<i;
    cout << ans << endl;

    return 0;
}