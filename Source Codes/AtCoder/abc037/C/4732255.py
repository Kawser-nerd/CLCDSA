#ABC037C
N, K = map(int, input().split())
A = list( map(int, input().split()) )
ans = sum( A[:K] )
now = sum( A[:K] )
for i in range(N-K):
	now -= A[i]
	now += A[i+K]
	ans += now
print(ans)