from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))
A = sorted(A)

D = defaultdict(int)
for i in A:
	D[i] += 1

d = []
for i in D:
	d.append(D[i])

ans = N
n = len(d)
if (N - n) % 2 == 0:
	print(n)
else:
	print(n - 1)