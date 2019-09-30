N, x = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

ans = sum(A)
for k in range(1, N + 1):
    A = [min(i, j) for i, j in zip(A, A[1:] + [A[0]])]
    ans = min(ans, x * k + sum(A))
print(ans)