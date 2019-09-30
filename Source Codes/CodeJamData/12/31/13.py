import sys
sys.setrecursionlimit(5000)

def check(i, graph, seen, mini):
	if seen[i] == True:
		return True, seen
	else:
		seen[i] = True
	for j in range(0, len(graph)):
		if graph[i][j]:
			res, seen = check(j, graph, seen, mini)
			if res: 
				return True, seen
	return False, seen


inFile = open('A-large.in','r')
outFile = open('diamond.out','w')
T = int(inFile.readline())
for n in range(1,T+1):
	N = int(inFile.readline())
	graph = [[False for i in range(N)] for i in range(N)]
	for i in range(N):
		l = [int(x) for x in inFile.readline().split()]
		for j in range(1,len(l)):
			graph[i][l[j]-1] = True
	
	res = False
	for i in range(N):
		# check if there's a diamond based at i
		res, seen = check(i,graph,[False for i in range(N)],i+1)
		if res: break
	if res:
		print('Case #'+str(n)+': Yes')
		outFile.write('Case #'+str(n)+': Yes\n')
	else:
		print('Case #'+str(n)+': No')
		outFile.write('Case #'+str(n)+': No\n')
