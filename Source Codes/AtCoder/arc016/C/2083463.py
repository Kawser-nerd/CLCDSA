N, M = map(int, input().split())
C = [None]*M
costs = [0]*M
for i in range(M):
    c, cost = map(int, input().split())
    C[i] = [list(map(int, input().split())) for i in range(c)]
    costs[i] = cost

ALL = 2 ** N - 1
memo = {ALL: 0.}
INF = 10**18
def dfs(state):
    if state in memo:
        return memo[state]
    res = INF
    for i in range(M):
        p = 0
        for c in C[i]:
            if state & (1 << (c[0]-1)):
                continue
            p += c[1]
        if p == 0:
            continue
        tmp = 0
        for c in C[i]:
            if state & (1 << (c[0]-1)):
                continue
            #tmp += c[1] * dfs(state | (1 << (c[0]-1))) / p
            tmp += c[1] * (dfs(state | (1 << (c[0]-1)))+costs[i])
        tmp = (costs[i]*(100-p) + tmp) / p
        res = min(res, tmp)
    memo[state] = res
    return res
print("%.10f" % dfs(0))