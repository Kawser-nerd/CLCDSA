N, M = map(int, input().split())
a = [0 for i in range(N)]
b = [0 for i in range(N)]
for i in range(N):
	a[i], b[i] = map(int, input().split())
c = [0 for i in range(M)]
d = [0 for i in range(M)]
for i in range(M):
	c[i], d[i] = map(int, input().split())

ans = [1 for i in range(N)]
for i in range(N):
	for j in range(M):
		if abs(a[i]-c[j])+abs(b[i]-d[j]) < abs(a[i]-c[ans[i]-1])+abs(b[i]-d[ans[i]-1]):
			ans[i] = j+1

for i in range(N):
	print(ans[i])