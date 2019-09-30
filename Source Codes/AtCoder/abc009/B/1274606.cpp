#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<int> A;

int main(void){
    cin >> N;
    A.resize(N);

    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    auto res = A.end() - 1;
    while( res != A.begin() && *res == *(A.end() - 1) ){
        res--;
    }
    cout << *res << endl;
}