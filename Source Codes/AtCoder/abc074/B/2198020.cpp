#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

typedef long long int Int;

int main(void) {
    int n,k;
    Int sum = 0;

    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        int x;
        cin>>x;
        sum += 2*min(abs(x-k),x);
    }

    cout<<sum<<endl;

    return 0;
}