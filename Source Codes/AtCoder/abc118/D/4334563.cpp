#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
#define INF (INT32_MAX)
//#define MOD (1000000000+7)
#define MAX 9
 
int N, M;
int A[MAX];
 
int num[9] = { 2, 5, 5, 4, 5, 6, 3, 7, 6 };


int main() {
	cin >> N >> M;
	int dp[N+1];

	//A[]??????????
	for( int i = 0; i < M; i++ ) {
		cin >> A[i];
	}
 	
 	//dp?N???????-INF???
	for( int i = 0; i <= N; i++ ) {
		dp[i] = -INF;
	}
	dp[0] = 0;
	for( int i = 1; i <= N; i++ ) {
		for( int j = 0; j < M; j++ ) {
			int a = A[j] - 1; 
			int n = num[a];
			if( i - n >= 0 ) {
				dp[i] = max( dp[i], dp[i - n] + 1 );
			}
		}
	}
	int d = dp[N];
	sort( A, A + M, greater<int>() );
	string ans;
	for( int i = 0; i < d; i++ ) {
		for( int j = 0; j < M; j++ ) {
			int a = A[j] - 1;
			int n = num[a];
			if( N - n >= 0 && dp[N - n] == dp[N] - 1 ) {
				ans += (char)(A[j] + '0');
				N -= n;
				break;
			}
		}
	}
 
	cout << ans << endl;
 
	return 0;
}