from collections import Counter
N, M = map(int, input().split())
A = [0] + [int(i) for i in input().split()]

for i in range(N):
    A[i + 1] += A[i]
    A[i + 1] %= M

ans = 0
for i in Counter(A).values():
    if i > 1:
        ans += i * (i - 1) // 2

print(ans)