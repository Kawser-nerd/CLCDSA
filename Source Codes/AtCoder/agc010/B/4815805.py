# ??
N = int(input())
A = list(map(int, input().split()))

S = sum(A)

# A_{i + 1} - A_i ???????
ans = (
    'YES' if (2 * S) % (N * (N + 1)) == 0 and all(
        k % N == 0 and k >= 0
        for k in (
            (2 * S) // (N * (N + 1)) - (A[i] - A[i - 1])
            for i in range(N)
        )
    ) else
    'NO'
)

# ??
print(ans)