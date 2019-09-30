#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

typedef long long int Int;

int main(void) {
    int N;
    cin>>N;
    vector<int> L(2*N);

    for(int i = 0;i < 2*N;i++) {
        cin>>L[i];
    }

    sort(L.begin(),L.end());

    Int sum = 0;
    for(int i = 0;i < 2*N;i += 2)
        sum += L[i];

    cout<<sum<<endl;

    return 0;
}