import sys

T=int(sys.stdin.readline())
INF = 10000000000

def dfs(GG, prev, nn, th):
	mmx = len(th)
#	print nn, th
	for p in nn:
		nth = th | GG[p]
		mx = dfs(GG, prev, prev[p], nth)
		if mx > mmx:
			mmx = mx
	return mmx

for case in range(T):
	print "Case #%d:" % (case+1),
	P, W = map(int, sys.stdin.readline().split(' '))
	
	G = []
	GG = dict()
	for i in range(P):
		G.append([False]*P)
		GG[i] = set([])
	
	for k in sys.stdin.readline().strip().split(' '):
		a,b = map(int, k.split(','))
		G[a][b] = True
		G[b][a] = True
		GG[a].add(b)
		GG[b].add(a)
	
	D = [INF]*P
	prev = []
	for i in range(P):
		prev.append([])

	D[0] = 0
	unseen = set(range(P))
	while len(unseen) > 0:
		dist = INF
		for knode in unseen:
			if D[knode] < dist:
				dist = D[knode]
				node = knode
		if dist == INF:
			break
		unseen.remove(node)
		for ch in range(P):
			if G[node][ch]:
				alt = D[node] + 1
				if alt < D[ch]:
					D[ch] = alt
					prev[ch] = [node]
				elif alt == D[ch]:
					prev[ch].append(node)
	
#	print prev

	mmx = dfs(GG, prev, prev[1], set([]))
	ll = D[1] - 1
	if ll > 0:
		mmx -= 1 # planet 0
	mmx -= ll
	print ll, mmx
