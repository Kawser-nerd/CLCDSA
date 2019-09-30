from collections import defaultdict

A = list(input())
N = len(A)
D = defaultdict(int)

for i in A:
    D[i] += 1

ans = 1 + int(N * (N - 1) / 2)

for i in D:
    ans -= int(D[i] * (D[i] - 1) / 2)

print(ans)