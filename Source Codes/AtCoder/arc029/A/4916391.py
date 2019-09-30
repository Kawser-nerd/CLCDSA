N = int(input())
t = [int(input()) for i in range(N)]

INF = 10**9
res = INF

for i in range(1 << N):
    plateA = 0
    plateB = 0
    for j in range(N):
        if ((i >> j) & 1):
            plateB += t[j]
        else:
            plateA += t[j]

    res = min(res, max(plateA, plateB))

print(res)