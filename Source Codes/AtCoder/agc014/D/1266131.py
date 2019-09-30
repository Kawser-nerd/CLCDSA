n = int(input())
tree = [[] for i in range(n)]
degree = [0 for i in range(n)]

for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)
    degree[a] += 1
    degree[b] += 1

leaf = []
for i in range(n):
    if degree[i] == 1:
        leaf.append(i)

color = ['' for i in range(n)]

first = False
while leaf:
    v = leaf.pop()
    if degree[v] == 0:
        first = True
        continue
    degree[v] = 0
    p = tree[v][0]
    # tree[p].remove(v)
    # degree[p] -= 1
    color[v] = 'B'
    color[p] = 'W'
    for np in tree[p]:
        tree[np].remove(p)
        degree[np] -= 1
        if degree[np] == 0:
            first = True
        elif degree[np] == 1:
            leaf.append(np)

for i in range(n):
    if color[i] == '' and degree[i] == 0:
        first = True

print('First' if first else 'Second')