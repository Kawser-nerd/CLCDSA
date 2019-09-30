import bisect

n = int(input())
a = sorted(list(map(int, input().split())))
a_t = [0]
for i in range(n):
    a_t.append(a[i] + a_t[i])
a_t = a_t[1:]
ans = 0
mi = 0
for i in range(n):
    index = bisect.bisect_right(a, a[i] * 2) - 1
    if index == n - 1:
        if not mi:
            mi = i
for i in range(n - 1, -1, -1):
    index = bisect.bisect_right(a, a_t[i] * 2) - 1
    if index >= mi:
        mi = i
        ans += 1
print(ans)