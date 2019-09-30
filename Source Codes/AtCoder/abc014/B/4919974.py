N, K = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

res = 0
for i in range(N):
    if (K >> i) & 1 == 1:
        res += A[i]

print(res)