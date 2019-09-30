import itertools

def is_edge_exists(node1, node2, edges):
	for edge in edges:
		if node1 in edge and node2 in edge:
			return True
	return False

def route_count(route, edges):
	if route[0]!=1:
		return 0
	for i in range(len(route)-1):
		if not is_edge_exists(route[i], route[i+1], edges):
			return 0
	return 1

N, M = map(int, input().split())
edges = [list(map(int, input().split())) for i in range(M)]
nodes = [i+1 for i in range(N)]
routes = list(itertools.permutations(nodes))

ans = 0
for route in routes:
	ans += route_count(route, edges)
print(ans)