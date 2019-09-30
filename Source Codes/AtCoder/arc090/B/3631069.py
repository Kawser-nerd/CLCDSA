from collections import deque
N, M = map(int, input().split())
Inf = 10000000000
Edge = [[] for i in range(N)]
for i in range(M):
    l, r, d = map(int, input().split())
    Edge[l-1].append((r-1, d))
    Edge[r-1].append((l-1, -d))
 
Node = [Inf for i in range(N)]
Possible = True
for i in range(N):
    if not Possible:
        break
    elif Node[i] == Inf:
        Node[i] = 0
        Q = deque([i])
        while Q:
            now = Q.popleft()
            for e in Edge[now]:
                if Node[e[0]] == Inf:
                    Node[e[0]] = Node[now] + e[1]
                    Q.append(e[0])
                elif Node[now] + e[1] != Node[e[0]]:
                    Possible = False
                    break
print("Yes" if Possible else "No")