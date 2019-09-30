N = int(input())
r = {}
b = {}
for _ in range(N):
    x,y = map(int,input().split())
    r[x] = y
r = sorted(r.items())

for _ in range(N):
    x,y = map(int,input().split())
    b[x] = y
b = sorted(b.items())

ans = 0
for v1 in b:
    x1,y1 = v1[0],v1[1]
    rmax = -1
    i = 0
    for v2 in r:
        x2,y2 = v2[0],v2[1]
        if x2 >= x1:
            break
        elif y2 < y1 and rmax < y2:
            rmax = y2
            delk = i
        i += 1
    if rmax != -1:
        del r[delk]
        ans += 1
print(ans)