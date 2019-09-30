def solve(a,b,N):
    up = []
    down = []
    keep = []
    for i in range(N):
        if a[i] < b[i]:
            down.append((a[i],b[i]))
        elif a[i] > b[i]:
            up.append((a[i],b[i]))
        else:
            keep.append((a[i],b[i]))
    up = list(reversed(sorted(up,key=lambda e:e[1])))
    down = sorted(down,key=lambda e:e[0])
    maxT = 0
    curT = 0
    for d in down:
        curT += d[0]
        if curT > maxT:
            maxT = curT
        curT -= d[1]
    for k in keep:
        curT += k[0]
        if curT > maxT:
            maxT = curT
        curT -= k[1]
    for u in up:
        curT += u[0]
        if curT > maxT:
            maxT = curT
        curT -= u[1]
    return maxT




N = int(input())
a = []
b = []
for _ in range(N):
    ai,bi = map(int,input().split())
    a.append(ai)
    b.append(bi)
print(solve(a,b,N))