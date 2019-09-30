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
    Int sum = 0;
    cin>>N;
    vector<int> A(N+2);
    A[0] = A[N+1] = 0;
    for(int i = 1;i <= N;i++) {
        cin>>A[i];
        sum += abs(A[i]-A[i-1]);
    }
    sum += abs(A[N+1]-A[N]);

    for(int i = 1;i <= N;i++) {
        cout<<sum - abs(A[i]-A[i-1])-abs(A[i+1]-A[i])+abs(A[i-1]-A[i+1])<<endl;
    }

    return 0;
}