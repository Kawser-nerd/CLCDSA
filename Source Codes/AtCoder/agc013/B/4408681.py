from collections import deque

n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

start = -1
for v in range(n):
    if len(g[v]) == 0:
        continue
    start = v
    break

memo = [0] * n
memo[start] = 1
count = 0
q1 = deque([])
q2 = deque([])
for v in g[start]:
    if memo[v] == 1:
        continue
    count += 1
    if count > 2:
        break
    memo[v] = 1
    if count == 1:
        q1.append(v)
    elif count == 2:
        q2.append(v)

ans1 = [start]
while q1:
    node = q1.popleft()
    ans1.append(node)
    flag = 0
    for nv in g[node]:
        if memo[nv] == 1:
            continue
        memo[nv] = 1
        q1.append(nv)
        flag = 1
        break
    if flag == 0:
        break

ans2 = []
while q2:
    node = q2.popleft()
    ans2.append(node)
    flag = 0
    for nv in g[node]:
        if memo[nv] == 1:
            continue
        memo[nv] = 1
        q2.append(nv)
        flag = 1
        break
    if flag == 0:
        break

ans1 = ans1[::-1]


ans = []
for i in ans1:
    ans.append(i+1)
for i in ans2:
    ans.append(i+1)
print(len(ans))
print(*ans)