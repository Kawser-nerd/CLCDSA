N,M=map(int, input().split())
py=[list(map(int, input().split())) for _ in range(M)]
cnt=[0]*(N+1)
ids={}
for p,y in sorted(py, key=lambda x: x[1]):
	cnt[p] += 1
	ids[y] = "%06d%06d" % (p, cnt[p])
for _,y in py:
	print(ids[y])