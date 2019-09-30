#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
    	cin >> A[i];
    }

    vector<int> cnt(100002, 0);

    for(int i = 0; i < N; i++) {
    	cnt[A[i]]++;
    	cnt[A[i] + 1]++;
    	cnt[A[i] + 2]++;
    }

    int ret = 0;
    for (int i = 0; i < 100002; i++) {
    	ret = max(ret, cnt[i]);
    }
    cout << ret << endl;
    return 0;
}