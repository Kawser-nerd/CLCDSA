H,W,N = map(int,input().split())
XY = []
for i in range(N):
    x,y = map(int,input().split())
    XY.append((x,y))

XY.sort()

ans,d = H,0
for xy in XY:
    x,y = xy[0],xy[1]
    if x == y+d:
        d += 1
    elif x > y+d:
        ans = min(ans, x-1)

print(ans)