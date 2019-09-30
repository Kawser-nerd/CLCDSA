N, M, X = (int(x) for x in input().split())
A = [int(x) for x in input().split()]
Z = [0] * N
for a in A:
    Z[a] = 1
lower = 0
for i in range(0, X+1):
    lower += Z[i]
higher = 0
for i in range(X, N):
    higher += Z[i]
print(min(lower,higher))