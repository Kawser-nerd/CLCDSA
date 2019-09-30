n, m = map(int, input().split())
edges = [set() for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].add(b)
    edges[b].add(a)
for i in range(n):
    x = set()
    for v in edges[i]:
        for w in edges[v]:
            if w not in edges[i] and w != i:
                x.add(w)
    print(len(x))