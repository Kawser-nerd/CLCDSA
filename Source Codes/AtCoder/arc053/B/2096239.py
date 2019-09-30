from collections import defaultdict
S = list(input())
N = len(S)

cnt = defaultdict(int)
for c in S:
	cnt[c] += 1

K = 0
for value in cnt.values():
	if value % 2 != 0:
		K += 1

res = 0
if K == 0:
	res = N
else:
	res = 2 * ((N - K) // (2 * K)) + 1

print(res)