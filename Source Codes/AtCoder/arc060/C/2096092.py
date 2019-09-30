# seishin.py
N = int(input())
*X, = map(int, input().split())
L = int(input())

K = 20

D = [[N]*(K+1) for i in range(N)]
j = N-1
for i in range(N-1, -1, -1):
    while j > 0 and X[j] - X[i] > L:
        j -= 1
    D[i][0] = j
for k in range(K):
    for i in range(N):
        if D[i][k] != N:
            D[i][k+1] = D[D[i][k]][k]
def solve(a, b):
    if not a < b:
        a, b = b, a
    res = 1
    for k in range(K, -1, -1):
        if D[a][k] < b:
            a = D[a][k]
            res += 2**k
    return res
Q = int(input())
ans = []
for i in range(Q):
    a, b = map(int, input().split())
    ans.append(solve(a-1, b-1))
print(*ans, sep='\n')