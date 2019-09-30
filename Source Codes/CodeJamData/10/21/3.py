T = int(raw_input())

for t in range(T):
	N,M = map(lambda x:int(x),raw_input().split())
	paths = set([])
	res = 0
	for i in range(N+M):
		path = raw_input()	
		while path != "":
			if not (path in paths):
				paths.add(path)
				if i >= N:
					res = res+1
			j = len(path)-1
			while (j >= 0) and (path[j] != '/'):
				j = j-1
			path = path[:j]

	print "Case #%d: %d"%(t+1, res)

