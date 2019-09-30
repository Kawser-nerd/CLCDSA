N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
INF = 10**9

def ok(time):
    l = b = -INF
    r = t = INF
    for x,y,c in src:
        l = max(l, x - time/c)
        r = min(r, x + time/c)
        if l > r: return False
        b = max(b, y - time/c)
        t = min(t, y + time/c)
        if b > t: return False
    return True

l = 0
r = INF*2
for i in range(50):
    m = (l+r) / 2
    if ok(m):
        r = m
    else:
        l = m
print(l)