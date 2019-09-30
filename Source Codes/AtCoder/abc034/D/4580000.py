N, K = map(int, input().split())
w = [0]*N
p = [0]*N
for i in range(N):
	w[i], p[i] = map(int, input().split())

low, high = 0, 100

while (high - low) > 1e-10:
	mid = (high + low)/2
	l = sorted([(p[i]-mid)*w[i] for i in range(N)], reverse=True)
	s = sum(l[:K])
	if s >= 0:
		low = mid
	else:
		high = mid
print(round(mid, 9))