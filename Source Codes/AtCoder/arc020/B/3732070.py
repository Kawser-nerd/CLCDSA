N, C = map(int, input().split())

A = [int(input()) for i in range(N)]

ans = float('inf')
for i in range(1, 11):
    for j in range(1, 11):
        if i == j:
            continue
        ans = min(N - A[::2].count(i) - A[1::2].count(j), ans)
print(ans * C)