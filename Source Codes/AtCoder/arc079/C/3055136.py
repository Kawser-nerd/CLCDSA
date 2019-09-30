n = int(input())
a = list(map(int, input().split()))
ans = 0

M = max(a)
m = min(a)
while M > n - 1:
	Mi = a.index(M)
	div = M // n
	for i in range(n):
		if i == Mi:
			a[i] -= n * div
		else:
			a[i] += div
	ans += div
	M = max(a)
	m = min(a)

print(ans)