import bisect
na,nb = map(int, input().split())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
n = 0
for i in a:
    x = bisect.bisect_left(b, i)
    if x < len(b):
        if b[x] == i:
            n += 1
ans = n/(len(a)+len(b)-n)
print(ans)