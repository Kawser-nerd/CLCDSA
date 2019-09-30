n, m = map(int, input().split())
c = []
for i in range(m):#h:??
    c.append([int(m) for m in input().split()])


graph = {}
for i in range(n):
    graph[i + 1] = []
for i in range(m):
    graph[c[i][0]] = graph[c[i][0]] + [c[i][1]]
    graph[c[i][1]] = graph[c[i][1]] + [c[i][0]]
stack = []
start = 1
i = start
visited = set()
visited.add(i)
root = [i]
while True:
    for j in graph[i]:
        if j not in visited:
            i = j
            root += [i]
            visited.add(i)
            break
    else:
        break
i = 1
root2 = []
while True:
    for j in graph[i]:
        if j not in visited:
            i = j
            root2 += [i]
            visited.add(i)
            break
    else:
        break
ver = len(root2) + len(root)
print(ver)
root = root2[::-1] + root
for i in root:
    print(i, "", end="")