#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    int n;
    vector<int> a;

    cin>>n;
    for(int i = 0;i < n;i++) {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    sort(a.begin(),a.end());
    if(n == 2) {
        cout<<a[1]<<" "<<a[0]<<endl;

        return 0;
    }
    int temp = a[n-1]/2;

    int min_diff = 1e9;
    int value = -1;
    for(int i = 0;i < n;i++) {

        if(abs(a[i] - temp) <= min_diff)
        {
            min_diff = abs(a[i] - temp);
           value = a[i];
        }
    }
    cout<<a[n-1]<<" "<<value<<endl;
    

    return 0;
}