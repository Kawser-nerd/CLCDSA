from bisect import bisect_right
N = int(input())
X = list(map(int, input().split()))
L = int(input())

P = [[0] * N for i in range(30)]
for i in range(N):
    q = bisect_right(X, X[i] + L)
    P[0][i] = q - 1

for i in range(1, 30):
    for j in range(N):
        P[i][j] = P[i - 1][P[i - 1][j]]


Q = int(input())
for i in range(Q):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    a, b = a - 1, b - 1
    num = 0
    for j in range(29, -1, -1):
        if P[j][a] < b:
            a = P[j][a]
            num += 2 ** j
    print(num + 1)