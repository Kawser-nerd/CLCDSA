import itertools
N, K = [int(_) for _ in input().split()]
A = [0] + [int(_) for _ in input().split()]

cumsum_p = list(
    itertools.accumulate([A[i] if A[i] > 0 else 0 for i in range(N + 1)]))
cumsum_m = list(
    itertools.accumulate([A[i] if A[i] < 0 else 0 for i in range(N + 1)]))
ans = -float('inf')
for i in range(N - K + 1):
    ans = max(ans, -(cumsum_p[i + K] - cumsum_p[i]),
              cumsum_m[i + K] - cumsum_m[i])
ans += cumsum_p[-1]
print(ans)