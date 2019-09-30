def DFS(G, U, V, x):
    V[x] = True
    for y in G[x]:
        if U[y] == -1 or (not V[U[y]] and DFS(G, U, V, U[y])):
            U[y] = x
            return True
    return False


def maximum_matching(G, na, nb):
    U = [-1] * nb
    size = 0
    for i in range(na):
        V = [False] * na
        if DFS(G, U, V, i):
            size += 1
    return size


def get_index(M, x):
    if x in M:
        return M[x]
    y = len(M)
    M[x] = y
    return y


def solve():
    m = int(input())
    MA = {}
    MB = {}
    E = []
    for _ in range(m):
        a, b = input().split()
        xa = get_index(MA, a)
        xb = get_index(MB, b)
        E.append((xa, xb))

    G = [[] for _ in range(len(MA))]
    for u, v in E:
        G[u].append(v)

    return m - len(MA) - len(MB) + maximum_matching(G, len(MA), len(MB))


t = int(input())

for i in range(t):
    print('Case #{}: {}'.format(i + 1, solve()))
