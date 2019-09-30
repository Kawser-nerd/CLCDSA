import re,sys
def _scans():
	while True:
		yield from input().split()
scans = _scans().__next__
scan = lambda: int(scans())
red = lambda *a,**kw:print(*a,**kw,file=sys.stderr)
inf = float('inf')
def calc():
	n,q = scan(),scan()
	horse = [(scan(),scan()) for i in range(n)]
	dist = [[scan() for i in range(n)] for i in range(n)]
	q = [(scan(),scan()) for i in range(q)]

	stp = [[sys.maxsize]*n for i in range(n)]
	for i in range(n):
		stp[i][i] = 0
	for i in range(n):
		for j in range(n):
			if dist[i][j] != -1:
				stp[i][j] = dist[i][j]
	for k in range(n):
		for i in range(n):
			for j in range(n):
				stp[i][j] = min(stp[i][j], stp[i][k] + stp[k][j])
	mt = [[inf]*n for i in range(n)]
	for i in range(n):
		mt[i][i] = 0
	for i in range(n):
		for j in range(n):
			if stp[i][j] <= horse[i][0]:
				mt[i][j] = stp[i][j] / horse[i][1]
	for k in range(n):
		for i in range(n):
			for j in range(n):
				mt[i][j] = min(mt[i][j], mt[i][k] + mt[k][j])
	out = []
	for qa,qb in q:
		out.append(mt[qa-1][qb-1])
	return out

'''
if True:
	'''
sys.stdin = open('input.txt')
with open('output.txt','w') as sys.stdout:#'''
	for t in range(scan()):
		red('Case #%d'%(t+1))
		print('Case #%d:'%(t+1),*calc())