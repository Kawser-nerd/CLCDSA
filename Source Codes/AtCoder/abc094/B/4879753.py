N, M, X = (int(x) for x in input().split())
A = [int(x) for x in input().split()]
Z = [0] * N
for a in A:
    Z[a] = 1

lower = 0
higher = 0
for i in range(0, N):
    lower += Z[i] if i < X else 0
    higher += Z[i] if i > X else 0
print(min(lower, higher))