#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int idx[200000];
    set<int> st;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        idx[a-1] = i;
    }
    long ans = 0;
    for(int i = 0; i < N; i++){
        st.insert(idx[i]);
        auto j = st.find(idx[i]);
        int lower, upper;
        if(j == st.begin()){
            //cout << 'H' <<endl;
            lower = -1;
        }
        else lower = *(--j);
        j = st.find(idx[i]);
        if(++j == st.end()) upper = N;
        else upper = *j;
        //cout << lower << ' ' << idx[i] << ' ' << upper << endl;
        ans += (long)(upper-idx[i])*(long)(idx[i]-lower)*(long)(i+1);
    }
    cout << ans << endl;
}