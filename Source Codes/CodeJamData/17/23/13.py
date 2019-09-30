from sys import stdin
readline = stdin.readline

T = int(readline())
for t in xrange(1, T+1):
	N, Q = map(int, readline().strip().split())
	
	Horses = []
	for i in xrange(N):
		E, S = map(int, readline().strip().split())
		Horses.append((E,S))
	
	Dist = [map(int, readline().strip().split()) for i in xrange(N)]
	for i in xrange(N):
		for j in xrange(N):
			if Dist[i][j] == -1:
				Dist[i][j] = float('inf')
	
	Queries = [map(int, readline().strip().split()) for q in xrange(Q)]
	
	#Dealing with horses###################
	Times = [[float('inf')]*N for i in xrange(N)]
	for i in xrange(N):
		curDist = [float('inf')]*N
		curDist[i] = 0
		
		Unvisited = set(range(N))
		Visited = set()
		
		while Unvisited:
			exploring = min(Unvisited, key = lambda x: curDist[x])
			if curDist[exploring] == float('inf'):
				break
			
			for j in xrange(N):
				curDist[j] = min(curDist[j], curDist[exploring] + Dist[exploring][j])
			
			Unvisited.remove(exploring)
			Visited.add(exploring)
		
		for j in xrange(N):
			if curDist[j] <= Horses[i][0]:
				Times[i][j] = min(Times[i][j], float(curDist[j])/Horses[i][1])
	##########################################
	
	answers = []
	for query in Queries:
		U, V = query[0]-1, query[1]-1
		#Reusing code
		curDist = Times[U][:]
		curDist[U] = 0
	
		Unvisited = set(range(N))
		Visited = set()
	
		while Unvisited:
			exploring = min(Unvisited, key = lambda x: curDist[x])
			if curDist[exploring] == float('inf'):
				break
		
			for j in xrange(N):
				curDist[j] = min(curDist[j], curDist[exploring] + Times[exploring][j])
		
			Unvisited.remove(exploring)
			Visited.add(exploring)
	
		ans = curDist[V]
		answers.append('%.8f' % ans)
	print "Case #%d: %s" % (t, ' '.join(answers))
