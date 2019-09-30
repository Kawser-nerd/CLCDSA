import sys
N, M = map(int, input().split())
edges = [[] for _ in [0]*(N+1)]
for a, b in (map(int, l.split()) for l in sys.stdin):
    edges[a].append(b)
    edges[b].append(a)

path = [1]
append = path.append
visited = [0, 1] + [0]*(N-1)

while True:
    if all(visited[v] for _v in (path[0], path[-1]) for v in edges[_v]):
        print(len(path))
        print(*path)
        exit()
    for v in edges[path[-1]]:
        if not visited[v]:
            visited[v] = 1
            append(v)
            break
    else:
        path.reverse()