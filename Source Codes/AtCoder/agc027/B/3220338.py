def E(i, x):
    if i == 1:
        return 5*x
    else:
        return (2*i + 1) * x

N, X = map(int, input().split())
G = [int(_) for _ in input().split()]
SumG = [0 for i in range(N)] 
SumG[0] = G[0]
for i in range(N-1):
    SumG[i+1] = SumG[i] + G[i+1]

pick = N * X
cost = float("inf")
for k in range(1, N+1): 
    trush = k * X
    carry = 0
    i, upper, lower = 1, N-1, N-1-k
    while lower >= 0:
        carry += E(i, SumG[upper]-SumG[lower])
        i, upper, lower = i+1, lower, lower - k
    carry += E(i, SumG[upper])
    cost = min(cost, pick + trush + carry)

print(cost)