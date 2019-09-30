import sys
sys.setrecursionlimit(10**7)

n, m = map(int, input().split())

v = [0] * n
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    v[a] += 1
    v[b] += 1
    g[a].append(b)
    g[b].append(a)

for i in range(n):
    if v[i] % 2 == 1:
        print("No")
        exit()

v4 = 0
for i in range(n):
    if v[i] >= 6:
        print("Yes")
        exit()
    if v[i] == 4:
        v4 += 1

if v4 == 0:
    print("No")
    exit()
if v4 == 1:
    print("No")
    exit()
if v4 >= 3:
    print("Yes")
    exit()


memo = [0] * n
ord = [0] * n
lowlink = [0] * n
articulation = [0] * n

def dfs(v, p, k):
    memo[v] = 1
    ord[v] = k
    lowlink[v] = ord[v]
    isArticulation = False
    count = 0
    for nv in g[v]:
        if memo[nv] == 0:
            count += 1
            dfs(nv, v, k+1)
            lowlink[v] = min(lowlink[v], lowlink[nv])
            if p != -1 and ord[v] <= lowlink[nv]:
                isArticulation = True
        elif nv != p:
            lowlink[v] = min(lowlink[v], ord[nv])

    if p == -1 and count > 1:
        isArticulation = True
    if isArticulation:
        articulation[v] = 1

dfs(0, -1, 0)

count = 0
for i in range(n):
    if v[i] == 4 and articulation[i] == 1:
        count += 1

if count >= 2:
    print("Yes")
else:
    print("No")