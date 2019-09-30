T = input()

from itertools import permutations, product

def _simul(adj, w, m):
    N = len(adj)
    if not w:
        return True
    nw = w[0]
    can_op = m & set([i for i in range(N) if adj[nw][i] == '1'])
    # print adj, w, m, can_op
    # print '_', adj, w,m, nw, can_op
    if m and not can_op:
        return False
    for op in can_op:
        if not _simul(adj, w[1:], m - {op}):
            return False
    return True

def simul(N, adj):
    # print N, adj
    for perm in permutations(range(N)):
        if not _simul(adj, perm, set(range(N))):
            return False
    return True

def subs(adj, am):
    m = 0
    for i in range(N):
        for j in range(N):
            if adj[i][j] == '1' and am[i][j] == '0':
                return None
            if adj[i][j] == '0' and am[i][j] == '1':
                m += 1
    return m

def solve(N, adj):
    mx = 10000
    for al in product('01', repeat=N * N):
        am = [[0 for i in range(N)] for j in range(N)]
        for i in range(N):
            for j in range(N):
                am[i][j] = al[i * N + j]
            am[i] = ''.join(am[i])
        x = subs(adj, am)
        if x is None:
            continue
        ok = simul(N, am)
        # print adj, am, x, ok
        if ok:
            mx = min(x, mx)
    return mx

for i in range(1, T + 1):
    N = input()
    adj = [None] * N
    for q in range(N):
        adj[q] = raw_input().strip()
    print 'Case #{}: {}'.format(i, solve(N, adj))

# print simul(3, ['100', '010', '001'])
