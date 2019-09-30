N, K = map(int, input().split())
l = list(map(int, input().split()))

ans = 0
for i in range(K):
	m = max(l)
	ans += m
	l[l.index(m)] = 0
print(ans)