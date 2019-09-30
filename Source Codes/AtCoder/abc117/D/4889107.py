n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for i in range(40, -1, -1):
    j = 2 ** i
    count = len([1 for temp in a if temp&j > 0])
    if count < n - count and j <= k:
        k -= j
        count = n - count
    ans += j * count
print(ans)