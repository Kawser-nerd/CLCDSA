n = int(input())
a = list(map(int, input().split()))
x = {}
for i in range(n):
    t = min(a[i] // 400, 8)
    if t in x.keys():
        x[t] += 1
    else:
        x[t] = 1
m = 0
l = len(x.keys())
if 8 in x.keys():
    ans = [max(1, l - 1), l - 1 + x[8]]
else:
    ans = [l, l]
print(*ans)