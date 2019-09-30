#From Submission #364517 by ??

n,k=map(int,input().split())

sums = []
for d in range(1, 32000):
	if d*d > k: break
	if k % d == 0:
		sums.append([d, (n//d)*(n//d+1)//2*d])
		if d * d != k:
			e = k//d
			sums.append([e, (n//e)*(n//e+1)//2*e])
sums.sort()
for i in range(len(sums)-1,-1,-1):
	for j in range(i):
		if sums[i][0] % sums[j][0] == 0:
	              sums[j][1] -= sums[i][1]
ret = 0
for v in sums:
	ret += v[1]*(k//v[0])
print(ret%1000000007)