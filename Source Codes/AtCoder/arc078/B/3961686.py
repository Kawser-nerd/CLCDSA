import heapq
N = int(input())
AB = [[int(_) for _ in input().split()] for _ in range(N - 1)]
G = {}
for a, b in AB:
    a -= 1
    b -= 1
    #0-indexed
    G[a] = G.get(a, set())
    G[b] = G.get(b, set())
    G[a].add(b)
    G[b].add(a)


def dijkstra_stack(i):
    D = [-1] * N
    D[i] = 0
    stack = [i]
    while True:
        i = stack.pop(0)
        update = False
        for j in G[i]:
            if D[j] == -1:
                update = True
                D[j] = D[i] + 1
                stack += [j]
        if not stack:
            break
    return D


D_Fennec = dijkstra_stack(0)
D_Snuke = dijkstra_stack(N - 1)

f = 0
s = 0
for i in range(N):
    if D_Fennec[i] <= D_Snuke[i]:
        f += 1
    else:
        s += 1
if f > s:
    print('Fennec')
else:
    print('Snuke')