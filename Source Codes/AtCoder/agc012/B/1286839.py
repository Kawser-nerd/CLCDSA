import sys
sys.setrecursionlimit(100000)

n, m = map(int,input().split())
node = [[] for i in range(n + 1)]

for i in range(m):
    a, b = map(int,input().split())
    node[a].append(b)
    node[b].append(a)

q = int(input())
vdc = [[0] * 3 for i in range(q)]
for i in range(q):
    vdc[i][0], vdc[i][1], vdc[i][2] = map(int, input().split())
vdc = vdc[::-1]

ans = [0] * (n + 1)
visited = [[0] * 11 for i in range(n + 1)]
def f(v, d, c):
    if d < 0:
        return
    if visited[v][d]:
        return

    visited[v][d] = 1
    if ans[v] == 0:
        ans[v] = c
        #print("ans", v, ans[v])

    for x in node[v]: #??x???v???????
        f(x, d - 1, c)

for v, d, c in vdc:
    f(v, d, c)

for i in range(n):
    print(ans[i + 1])