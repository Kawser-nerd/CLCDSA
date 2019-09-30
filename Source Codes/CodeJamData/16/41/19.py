a = [['P', 'R', 'S']]
u = 'PRS'
for n in range(1, 13):
	v = []
	for t in range(3):
		x, y = a[n-1][t], a[n-1][(t+1) % 3]
		v.append(min(x+y, y+x))
	a.append(v)



T = int(input())
for i in range(T):
	N, r, p, s = map(int, input().split())
	res = 'IMPOSSIBLE'
	for u in a[N]:
		if u.count('R') == r and u.count('S') == s and u.count('P') ==p:
			if res == 'IMPOSSIBLE':
				res = u
			else:
				res = min(res, u)
	print("Case #%d:"%(i+1), res)
