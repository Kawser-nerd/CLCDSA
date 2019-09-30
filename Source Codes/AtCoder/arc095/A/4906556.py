N = int(input())
X = list(map(int, input().split()))

SX = [[i, X[i]] for i in range(len(X))]
SX = sorted(SX, key=lambda x:x[1])

lm = SX[N//2-1][1]
rm = SX[N//2][1]

res = [0] * N
for i in range(len(SX)):
    if i < N // 2:
        res[SX[i][0]] = rm
    else:
        res[SX[i][0]] = lm


for r in res:
    print(r)