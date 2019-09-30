n = int(input())
a = list(map(int, input().split()))
b = [(a[i], i) for i in range(n)]
b.sort()
ans = [0 for i in range(n)]
ans[0] = b[0][0] * n
min_index = b[-1][1]
for i in range(n-1, 0, -1):
    min_index = min(min_index, b[i][1])
    if b[i-1][0] != b[i][0]:
        ans[min_index] += (b[i][0] - b[i-1][0]) * (n-i)
for i in range(n):
    print(ans[i])