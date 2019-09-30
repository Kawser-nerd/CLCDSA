import bisect
n = int(input())
a = list(map(int, input().split()))
a.sort()
b = a[-1] / 2
i = bisect.bisect(a, b)
if a[i] - b < b - a[i - 1]:
    print(a[-1], a[i])
else:
    print(a[-1], a[i - 1])