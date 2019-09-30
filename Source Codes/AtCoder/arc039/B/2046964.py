MOD = 10**9 + 7
N,K = map(int,input().split())

def nCk(n,k):
	res = 1
	k = min(n, n-k)
	for i in range(k):
		res *= (n - i)
	for i in range(k):
		res //= (k - i)
	return res

res = 0
if N > K:
	res = nCk(N - 1 + K , K) % MOD
elif N == K:
	res = 1
else: # if N < K:
	K %= N
	res = nCk(N,K) % MOD 

print(res)