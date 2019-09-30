import sys
sys.setrecursionlimit(10**8)

n = int(input())
ps = []
cs = [[] for _ in range(n)]
for i in range(1, n):
	a = int(input())
	ps.append(a-1)
	cs[a-1].append(i)
depths = [10**10 for _ in range(n)]
for i in range(1, n):
	if not cs[i]:
		depths[i] = 0

def search(x):
	for c in cs[x]:
		if depths[c] > 10**9:
			search(c)
	d_list = sorted([depths[c] for c in cs[x]], reverse=True)
	Ma = 0
	for d, i in enumerate(d_list):
		Ma = max(Ma, d+i+1)
	depths[x] = Ma
	return

search(0)
print(depths[0])