from collections import defaultdict
def mod_pow(x, n, mod):
	if n == 0:
		return 1
	res = mod_pow(x * x % mod, n // 2, mod)
	if n & 1:
		res = res * x % mod
	return res

MOD = 10**9 + 7

N = int(input())
A = list(map(int,input().split()))

ok = True
zeros = 0
cnt = defaultdict(int)

for i in range(N):
	if i == 0:
		if A[i] != 0:
			ok = False
	if A[i] == 0: 
		zeros += 1
	cnt[A[i]] += 1

maxn = max(cnt.keys())

if zeros != 1:
	ok = False

res = 1
if ok == True:
	for i in range(0,maxn+1):
		if i != 0 and cnt[i] == 0:
			ok = False;
			break
		K = cnt[i]
		res = (res * mod_pow(2,K*(K-1)//2,MOD)) % MOD
		if i != 0:
			t = cnt[i-1]
			curr = mod_pow(2,t,MOD)
			s = cnt[i]
			curr2 = mod_pow(curr - 1 + MOD, s, MOD)
			res = (res * curr2) % MOD

print(res if ok == True else 0)