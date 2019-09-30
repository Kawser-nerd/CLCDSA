import sys
n, m = map(int, input().split())
N = 2000
G = [[0] * N for i in range(N)]
dp = [[0] * N for i in range(N)]
col = [0] * N
cnt = [0] * 2
visit = [0] * N
for i in range(m):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    G[a][b], G[b][a] = 1, 1


def dfs(u, c):
    visit[u] = 1
    col[u] = c
    cnt[c] += 1

    for v in range(n):
        if v == u or G[u][v] == 1:
            continue

        if visit[v] == 1 and col[v] == c:
            return False

        if not visit[v] and not dfs(v, c ^ 1):
            return False

    return True


num = 0
dp[0][0] = 1
for i in range(n):
    if not visit[i]:
        num += 1

        cnt[0], cnt[1] = 0, 0

        if not dfs(i, 0):
            print(-1)
            sys.exit()

        for j in range(n):
            for k in range(2):
                if j >= cnt[k]:
                    dp[num][j] |= dp[num - 1][j - cnt[k]]

ans = m
for i in range(n):
    if dp[num][i]:
        ans = min(ans, i * (i - 1) // 2 + (n - i) * (n - i - 1) // 2)

print(ans)