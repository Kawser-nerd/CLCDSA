n, m = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n)]
ab.sort(key = lambda x: x[0])
total = 0
i = 0
while True:
	total += ab[i][1]
	if total < m:
		i += 1
	else:
		break
ans = 0
for j in range(i):
	ans += ab[j][0] * ab[j][1]
ans += (m - sum(ab[p][1] for p in range(0,i))) * ab[i][0]
print(ans)