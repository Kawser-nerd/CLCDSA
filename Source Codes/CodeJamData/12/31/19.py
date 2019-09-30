#!/usr/bin/env python
def iterative_dfs(graph, start, path=[]):
	'''iterative depth first search from start'''
	q=[start]
	while q:
		v=q.pop(0)
		if v not in path:
			path=path+[v]
			q=graph[v]+q
	return path

def iterative_bfs(graph, start, path=[]):
	'''iterative breadth first search from start'''
	q=[start]
	while q:
		v=q.pop(0)
		if not v in path:
			path=path+[v]
			q=q+graph[v]
	return path


T = int(raw_input())
for t in range(1, T+1):
	N = int(raw_input())
	G = dict()
	
	for i in range(1, N+1):
		G[i] = []
	
	for i in range(1, N+1):
		line = map(int, raw_input().split())[1:]
		for j in line:
			G[i].append(j)		
	
	parents = dict()
	for i in G:
		parents[i] = set(iterative_bfs(G, i, []))
	
	diamond = False
	for node in G:
		if diamond:
			break
		visited = set()
		for par in G[node]:
			if diamond:
				break
			for x in parents[par]:
				if x in visited:
					diamond = True
					break
				else:
					visited.add(x)
			
	print "Case #{0}: {1}".format(t, "Yes" if diamond else "No")
	
				