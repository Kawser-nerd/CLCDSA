import sys

k = int(input())
a = list(map(int, input().split()))[::-1]

m, M = 2, 2

for i in range(k):
	if m % a[i] != 0:
		m += a[i] - (m % a[i])

	M = M - (M % a[i]) + a[i] - 1

	if m > M:
		print(-1)
		sys.exit()

print(m, M)