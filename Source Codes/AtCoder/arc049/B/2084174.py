N = int(input())
x = [0] * N
y = [0] * N
c = [0] * N
for i in range(N):
	x[i], y[i], c[i] = map(int,input().split())

INF = 10**9
def bin_search(t):
	global x, y, c, N, INF
	left = bottom = -INF
	right = top = INF
	for i in range(N):
		left  = max(left,  x[i] - t / c[i])
		right = min(right, x[i] + t / c[i])
		if left > right:
			return False
		bottom = max(bottom, y[i] - t / c[i])
		top    = min(top,    y[i] + t / c[i])
		if bottom > top:
			return False
	return True

left = 0
right = INF * 2
for i in range(64):
	mid = (left + right) / 2
	if bin_search(mid):
		right = mid
	else:
		left = mid

print(left)