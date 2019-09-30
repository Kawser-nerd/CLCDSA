B = [list(map(int, input().split())) for i in range(2)]
C = [list(map(int, input().split())) for i in range(3)]

dp = [None] * (1 << 18)

def dfs(s, t, h):
    if dp[s << 9 | t]: return dp[s << 9 | t]
    if h == 9:
        g = [0] * 9
        for i in range(9):
            g[i] = 1 if s >> i & 1 else 2
        r = [0, 0]
        for i in range(2):
            for j in range(3):
                r[g[i * 3 + j] != g[(i + 1) * 3 + j]] += B[i][j]
        for i in range(3):
            for j in range(2):
                r[g[i * 3 + j] != g[i * 3 + j + 1]] += C[i][j]
        dp[s << 9 | t] = r
        return r
    cnd = [i for i in range(9) if ~s >> i & 1 and ~t >> i & 1]
    wei = map(lambda i: dfs(s | (1 << i) * (~h & 1), t | (1 << i) * (h & 1), h + 1), cnd)
    dp[s << 9 | t] = sorted(wei, key=lambda x: -x[h & 1])[0]
    return dp[s << 9 | t]

print('\n'.join(map(str, dfs(0, 0, 0))))