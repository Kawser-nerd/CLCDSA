#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
long long nibeki(long long a){
    long long t = 1;
    while(a >= t){
        t = 2*t;
    }
    return t;
}
int main(){
    multiset<long long> st;
    int n,p;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> p;
        st.insert(p);
    }
    long long q,r;
    long ans = 0;
    while(!st.empty()){
        auto tem = st.end();
        tem--;
        q = nibeki(*tem) - *tem;
        if(q != *tem){
            ans = ans + min(st.count(*tem),st.count(q));
            if(st.count(*tem)>=st.count(q)){
                st.erase(*tem);
                st.erase(q);
            }
            else{
                r = st.erase(q) - st.erase(*tem);
                st.erase(*tem);
                st.erase(q);
                for(int i = 0;i<r;i++){
                    st.insert(q);
                }
            }
        }
        else{
            ans = ans + (st.count(*tem))/2;
            st.erase(*tem);
        }
    }
    cout << ans << endl;
}