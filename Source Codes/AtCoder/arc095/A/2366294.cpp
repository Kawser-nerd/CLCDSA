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
    int N;
    vector<int> A,B;
    cin>>N;

    int l = N-1;

    int m = (l+1)/2;
    B.push_back(0);
    for(int i = 1;i <= N;i++) {
        int temp;
        cin>>temp;
        A.push_back(temp);
        B.push_back(temp);
    }

    sort(B.begin()+1,B.end());

    int index = m;
    for(int i = 1;i <= N;i++) {
        if(A[i-1] <= B[index]) {
            cout<<B[index+1]<<endl;
        } else {
            cout<<B[index]<<endl;
        }
    }

    return 0;
}