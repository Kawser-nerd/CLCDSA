import bisect
a = []
for pw in range(2,1001):
    for x in range(1,1001):
        nw = x**pw
        if nw > 1000:
            break
        a.append(nw)
a = sorted(a)
x = int(input())
y = bisect.bisect_right(a,x)
print(a[y-1])