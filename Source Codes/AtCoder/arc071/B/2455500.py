n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
MOD = 10 ** 9 + 7

ax = 0
ay = 0

for i in range(n):
	ax = (ax + (((2 * i - n + 1) * x[i]) % MOD)) % MOD

for i in range(m):
	ay = (ay + (((2 * i - m + 1) * y[i]) % MOD)) % MOD

print(int((ax * ay) % MOD))