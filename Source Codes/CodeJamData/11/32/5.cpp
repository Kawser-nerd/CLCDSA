#include<cstdio>
#include<vector>
#include<algorithm>
inline long long min(long long A, long long B){return A < B? A: B;}
long long sum, tm, arr[1001];
int T, N, C, L;
std::vector<long long> lst;
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		sum = 0;
		lst.clear();
		scanf("%d%I64d%d%d", &L, &tm, &N, &C);
		for(int i = 0; i < C; i++)
		    scanf("%I64d", &arr[i]);
		for(int i = 0, j = 0; i < N; i++, j++){
			if(j == C)j -= C;
			sum += arr[j] * 2;
			if(sum > tm){
				long long tmp = min((sum - tm) / 2, arr[j]);
				lst.push_back(tmp);
			}
		}
		std::sort(lst.begin(), lst.end());
		int len = lst.size();
		for(int i = 0; i < L; i++)
			sum -= lst[len - i - 1];
		printf("Case #%d: %I64d\n", t, sum);
	}
}
