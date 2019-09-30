#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long int ll;

int N;
vector<int> A;

int main() {
    cin >> N;

	int p = 0;
	int sum = 0;
	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
		A.push_back(x);
		sum += abs(x-p);
		p = x;
	}
	sum += abs(p);

	for(int i=0; i<N; i++) {
		int ans;
		int current = A[i];
		int pre = (i==0 ? 0 : A[i-1]);
		int post = (i==N-1 ? 0 : A[i+1]);

		if ( (current>pre && current<post) ||  (current < pre && current > post) ) {
			ans = sum;
		}else{
			ans = sum - 2 * min(abs(pre-current), abs(post-current));
		}
		cout << ans << endl;
	}
}