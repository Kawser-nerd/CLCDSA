n, m = map(int, input().split())
a = list(map(int, input().split()))
bitween = [0 for i in range(2 * m + 10)]
edge = [[] for i in range(m + 1)]

ans = 0
for i in range(n - 1):
	l, r = a[i], a[i + 1]
	if l >= r:
		r += m
	bitween[l + 2] += 1
	bitween[r + 1] -= 1

	edge[a[i + 1]].append(i)

for i in range(2 * m + 1):
	bitween[i + 1] += bitween[i]

ans = 0
for i in range(n - 1): # x = 1
	ans += min((a[i + 1] - a[i] + m) % m, (a[i + 1] - 1 + m) % m + 1)
prv = ans
for i in range(2, m + 1): # x >= 2
	crt = prv - bitween[i] - bitween[i + m]
	for j in edge[i - 1]:
		crt -= min((a[j + 1] - a[j] + m) % m, (a[j + 1] - (i - 1) + m) % m + 1)
		crt += min((a[j + 1] - a[j] + m) % m, (a[j + 1] - i + m) % m + 1 )
	ans = min(ans, crt)
	prv = crt
print(ans)