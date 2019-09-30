"""
ID: ashish1610
PROG:
LANG: Python
"""
prob = []
dp = [[]]
def func(cur, rem):
	if cur < 0:
		if rem > 0 or rem < 0:
			return 0.0
		else:
			return 1.0
	if rem < 0:
		return 0.0
	if dp[cur][rem] < 0:
		dp[cur][rem] = func(cur - 1, rem - 1) * (1 - prob[cur])
		dp[cur][rem] += func(cur - 1, rem) * prob[cur]
	return dp[cur][rem]
t = input()
for tcase in range(1, t + 1):
	n, k = map(int, raw_input().split())
	ar = [float(x) for x in raw_input().split()]
	ar.sort()
	res = 0.0
	for i in range(n):
		prob = []
		for j in range(i, n):
			prob.append(ar[j])
		for j in range(i):
			prob.append(ar[j])
		dp = [[-1 for i1 in range(n + 1)] for j1 in range(n + 1)]
		res = max(res, func(k - 1, k / 2))
	print("Case #%d: %0.9lf" % (tcase, res))
