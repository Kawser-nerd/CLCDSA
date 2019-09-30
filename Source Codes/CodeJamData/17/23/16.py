import numpy as np
from priodict import priorityDictionary

INF = float("inf")

def Dijkstra(G,start,end=None):

	D = {}	# dictionary of final distances
	P = {}	# dictionary of predecessors
	Q = priorityDictionary()   # est.dist. of non-final vert.
	Q[start] = 0
	n = len(G)
	
	for v in Q:
		D[v] = Q[v]
		if v == end: break
		
		for w in range(n):
			vwLength = D[v] + G[v][w]
			if w in D:
				if vwLength < D[w]:
					raise ValueError
			elif w not in Q or vwLength < Q[w]:
				Q[w] = vwLength
				P[w] = v
	
	return (D,P)

def fullDijkstra(Gtable):
	n = len(Gtable)
	ans = []
	for i in range(n):
		ans.append([INF]*n)
	for i in range(n):
		result, _ = Dijkstra(Gtable, i)
		for j in range(n):
			if j in result:
				ans[i][j] = result[j]
	return ans


inname = "input.txt"
outname = "output.txt"

with open(inname, 'r') as f:
	cases = int(f.readline())
	for tc in range(1,cases+1):
		line = f.readline().strip().split(' ')
		N = int(line[0])
		Q = int(line[1])
		Ei = []
		Si = []
		dist = []
		Uk = []
		Vk = []
		for i in range(N):
			line = f.readline().strip().split(' ')
			Ei.append(int(line[0]))
			Si.append(int(line[1]))
		for i in range(N):
			line = f.readline().strip().split(' ')
			dist.append([])
			for j in range(N):
				d = int(line[j])
				if d == -1:
					dist[i].append(INF)
				else:
					dist[i].append(d)
		for i in range(Q):
			line = f.readline().strip().split(' ')
			Uk.append(int(line[0]))
			Vk.append(int(line[1]))

		fulldist = fullDijkstra(dist)
		timegraph = []
		for i in range(N):
			timegraph.append([])
			for j in range(N):
				if i==j:
					timegraph[i].append(INF)
				else:
					if fulldist[i][j] > Ei[i]:
						timegraph[i].append(INF)
					else:
						timegraph[i].append(fulldist[i][j] / Si[i])
		#print(timegraph)
		fulltimegraph = fullDijkstra(timegraph)

		#print(fulltimegraph)
		ans = []
		for i in range(Q):
			ans.append(str(fulltimegraph[Uk[i]-1][Vk[i]-1]))
		print("Case #%d: %s" % (tc, " ".join(ans)))
