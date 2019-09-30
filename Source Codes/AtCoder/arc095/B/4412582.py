from bisect import bisect_left
n = int(input())
a = sorted(list(map(int, input().split())))
r = bisect_left(a, a[-1]/2)
l = r-1 if r else 0
if abs(a[-1]/2 - a[l]) > abs(a[-1]/2 - a[r]):
    l,r = r,l
print(a[-1],a[l])