from bisect import bisect_left
n = int(input())
red = sorted([list(map(int, input().split())) for i in range(n)])
blue = sorted([list(map(int, input().split())) for i in range(n)])

ans = 0
for x,y, in blue:
    i = bisect_left([a[0] for a in red], x)
    tmp = sorted(red[:i], key=lambda x:x[1], reverse=True)
    for xx, yy in tmp:
        if y > yy:
            ans += 1
            red.remove([xx,yy])
            break
print(ans)