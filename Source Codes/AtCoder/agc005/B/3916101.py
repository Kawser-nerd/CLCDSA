n = int(input())
a = list(map(int, input().split()))
index = [[] for _ in range(n+1)]
for i in range(n):
	index[a[i]] = i

l = list(range(n))
r = list(range(n))

ans = 0
for i in range(n, 0, -1):
	m = index[i]
	ans += i * (r[m] - m + 1) * (m - l[m] + 1)
	if l[m] > 0:
		r[l[m] - 1] = r[m]
	if r[m] < n-1:
		l[r[m] + 1] = l[m]

print(ans)