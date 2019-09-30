N = int(input())
F = [list(map(int, input().split())) for i in range(N)]
P = [list(map(int, input().split())) for i in range(N)]

ans = -10 ** 10

def calc(b):
    p = 0
    for i in range(N):
        c = 0
        for j in range(10):
            c += F[i][j] * b[j]
        p += P[i][c]
    return p

def dfs(b):
    global ans
    if len(b) == 10:
        if max(b) == 0:
            return
        ans = max(ans, calc(b))
        return
    dfs(b + [0])
    dfs(b + [1])

dfs([0])
dfs([1])
print(ans)