from collections import deque

N, M = map(int, input().split())
e = [[] for _ in range(N)]
# e[v]: ???????

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    e[a].append(b)
    e[b].append(a)

ans = [0]
ans = deque(ans)
# 0-indexed???????1-indexed???

in_path = [False] * N
in_path[0] = True
# ????????

while True:
    f = ans[0]
    for v in e[f]:
        if not in_path[v]:
            ans.appendleft(v)
            in_path[v] = True
            break
    else:
        break

while True:
    b = ans[-1]
    for v in e[b]:
        if not in_path[v]:
            ans.append(v)
            in_path[v] = True
            break
    else:
        break

print(len(ans))
print(*list(map(lambda x: x + 1, ans)))