#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<uint64_t> A(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cout << A.back() - A.front() << endl;

    return 0;
}