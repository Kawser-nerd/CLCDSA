N, M = map(int, input().split())
edge = [set() for _ in range(N + 1)]
for _ in range(M):
    l, r, d = map(int, input().split())
    edge[l].add((r, d))
    edge[r].add((l, -d))

loc = {}
for i in range(1, N + 1):
    stack = []
    if i not in loc:
        loc[i] = 0
        stack.append(i)
    while stack:
        s = stack.pop()
        for t, d in edge[s]:
            if t not in loc:
                loc[t] = loc[s] + d
                stack.append(t)
            elif loc[t] != loc[s] + d:
                print('No')
                exit()

# ??????????????
print('Yes')