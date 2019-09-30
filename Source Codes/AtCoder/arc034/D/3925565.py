A, B, C = map(int, input().split())
*X, = map(int, input().split())
*Y, = map(int, input().split())
R = sum(X) / A
L = [1]*(B+1)
memo = [[None]*(B+1) for i in range(B+1)]
def dfs(c, k):
    if k == 0:
        return 1.
    if c == B:
        return 0
    if memo[c][k] is not None:
        return memo[c][k]
    r = dfs(c+1, k) + dfs(c+1, k-1)*Y[c]
    memo[c][k] = r
    return r


for i in range(1, B+1):
    r = dfs(0, i)
    for j in range(0, i):
        r *= (i-j)/(B-j)
    L[i] = r

memo = [[-1]*(B+1) for i in range(A+1)]
def dfs(a, b):
    if memo[a][b] != -1:
        return memo[a][b]
    r = 0
    if a > 0:
        r += (dfs(a-1, b) + R*L[B-b]) * a
    if b > 0:
        r += dfs(a, b-1) * b
    r = memo[a][b] = r / (a+b+C)
    return r
print(dfs(A, B))