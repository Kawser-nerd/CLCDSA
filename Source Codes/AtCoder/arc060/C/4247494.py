from bisect import bisect

n = int(input())
x = list(map(int, input().split()))
l = int(input())
q = int(input())

#r[i][j]: j??(2**i)???????
r = [[i for i in range(n)] for _ in range(18)]
for j in range(n):
	r[0][j] = bisect(x, x[j]+l) - 1
for i in range(1, 18):
	for j in range(n):
		r[i][j] = r[i-1][r[i-1][j]]

def search(x, y):
	res = 0
	cur = x
	while True:
		for i in range(18):
			if r[i][cur] >= y:
				if i == 0:
					return res+1
				cur = r[i-1][cur]
				res += 1 << (i-1) 
				break

for _ in range(q):
	a, b = map(int, input().split())
	print(search(min(a, b)-1, max(a, b)-1))