N, A, B, C = [int(x) for x in input().split()]

lst = [int(input()) for i in range(N)]

INF = 10 ** 18

def dfs(cur, a, b, c):
    if cur == N:
        return abs(A - a) + abs(B - b) + abs(C - c) - 30 if min(a, b, c) > 0 else INF
 
    ptn1 = dfs(cur + 1, a, b, c)
    ptn2 = dfs(cur + 1, a + lst[cur], b, c) + 10
    ptn3 = dfs(cur + 1, a, b + lst[cur], c) + 10
    ptn4 = dfs(cur + 1, a, b, c + lst[cur]) + 10

    return min(ptn1, ptn2, ptn3, ptn4)

print(dfs(0, 0, 0, 0))