N, M = map(int, input().split())
a = [0 for i in range(M)]
b = [0 for i in range(M)]
ans = [0 for i in range(N)]
for i in range(M):
	a[i], b[i] = map(int, input().split())
	ans[a[i]-1] += 1
	ans[b[i]-1] += 1
for i in range(N):
	print(ans[i])