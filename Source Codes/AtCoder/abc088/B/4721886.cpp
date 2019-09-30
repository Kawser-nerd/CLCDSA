#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, a;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i)
    {
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    int alice = 0;
    int bob = 0;
    
    if(N % 2 == 0) {
        for(int i = 0; i < N; i += 2){
            bob += A[i];
            alice += A[i+1];
        }
    } else {
         for(int i = 0; i < N; i += 2){
            alice += A[i];
            bob += A[i+1];
        }
    }

    cout << alice - bob << endl;

    return 0;
}