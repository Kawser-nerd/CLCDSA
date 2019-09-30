import sys, collections
def input():
	return sys.stdin.readline()[:-1]

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

def calc(s):#s: ????????????set
	c = collections.Counter()
	for i in range(n):
		for j in range(m):
			if a[i][j] not in s:
				c[a[i][j]] += 1
				break
	tmp = [-1, -1]
	for k, v in c.items():
		if v > tmp[1]:
			tmp = [k, v]
	del c
	return tmp

ans, boycott = n, set()

for _ in range(m-1):
	res = calc(boycott)
	ans = min(ans, res[1])
	boycott.add(res[0])

print(ans)