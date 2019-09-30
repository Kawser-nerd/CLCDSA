N,M = map(int,input().split())
x,a,p = map(int,input().split())

rank = []
for i in range(N*M):
	rank.append((x, i // M, i % M))
	x = (x + a) % p

rank.sort()

res = 0
for i in range(N):
	xs = []
	for j in range(M):
		s, y, x = rank[i * M + j]
		res += abs(y - i)
		xs.append(x)
	xs = sorted(xs)
	for j in range(M):
		res += abs(xs[j] - j)

print(res)