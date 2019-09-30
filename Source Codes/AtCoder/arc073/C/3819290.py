def inpl(): return [int(i) for i in input().split()]

N = int(input())
C = [()]*N
X = [0]*N
Y = [0]*N
for i in range(N):
    x, y = inpl()
    if x > y:
        x, y = y, x
    X[i] = x
    Y[i] = y
    C[i] = (x,y)
minx, maxx, miny, maxy = min(X), max(X), min(Y), max(Y)
ans = (maxy - miny)*(maxx - minx)
ix = X.index(minx)
iy = Y.index(maxy)
l, r = X[iy], Y[ix]
if r < l:
    l, r = r, l
H = []
for x, y in C:
    if y <= l:
        l = y
        continue
    if x >= r:
        r = x
        continue
    H.append((x,y))
Candi = []
for x, y in H:
    if l <= x <= r or l <= y <= r:
        continue
    Candi.append((x,y))
Candi.sort()
for x, y in Candi:
    ans = min(ans, (maxy - minx)*(r - x))
    r = max(r, y)
ans = min(ans, (maxy - minx)*(r - l))
print(ans)