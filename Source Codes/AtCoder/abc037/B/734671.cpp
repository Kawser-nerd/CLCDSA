#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> vec(n, 0);
    for(int i=0; i<q; i++) {
        int l, r, t;
        cin>>l>>r>>t;
        for (int j=l-1; j<=r-1; j++) {
            vec[j] = t;
        }
    }
    for(int i:vec) {
        cout<<i<<endl;
    }
}