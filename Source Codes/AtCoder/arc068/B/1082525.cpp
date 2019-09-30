#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> V(N);
    for(int i=0;i<N;i++){
        cin>>V[i];
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    int ans = V.size();
    if((N-ans)%2)ans--;
    cout<<ans<<endl;
    return 0;
}