n, m, c = map(int, input().split())
b = list(map(int, input().split()))
a = [list(map(int, input().split())) for i in range(n)]
count = 0
for i in range(n):
	total = 0
	for j in range(m):
		total += a[i][j] * b[j]
	total += c
	if total > 0:
		count += 1
print(count)