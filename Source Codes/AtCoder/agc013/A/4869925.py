n = int(input())
a = list(map(int, input().split()))
d = [0 for _ in range(n-1)]
for i in range(n-1):
    d[i] = a[i+1] - a[i]
cnt = 1
l = r = cur = 0
while l < n-1:
    while r < n-1 and cur * d[r] >= 0:
        if cur == 0:
            cur = d[r]
        r += 1
    if r < n-1 and cur * d[r] < 0:
        cnt += 1
    r += 1
    l = r
    cur = 0
print(cnt)