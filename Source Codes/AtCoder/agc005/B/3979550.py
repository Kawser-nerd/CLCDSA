N = int(input())
A = [int(_) for _ in input().split()]
left = list(range(N + 2))
right = list(range(N + 2))
index = {A[i - 1]: i for i in range(1, N + 1)}
ans = 0
for a in range(N, 0, -1):
    i = index[a]
    l = left[i]
    r = right[i]
    ans += a * (i - l + 1) * (r - i + 1)
    left[r + 1] = l
    right[l - 1] = r
print(ans)