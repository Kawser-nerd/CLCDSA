n, k = map(int, input().split())
r = list(map(int,input().split()))
r.sort()
del r[:(n-k)]
c = 0
for i in r:
	c = (c + i) / 2
print(c)