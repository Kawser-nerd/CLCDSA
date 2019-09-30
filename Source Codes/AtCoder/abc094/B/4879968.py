N, M, X = (int(x) for x in input().split())
A = [int(x) for x in input().split()]
lower = 0
higher = 0
for a in A:
    lower += 1 if a < X else 0
    higher += 1 if a > X else 0
print(min(lower, higher))