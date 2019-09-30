n, m = map(int, input().split())
p = list(range(n+1))
x = [0]*(n+1)
def find(i):
    if p[i] == i:
        return i
    p[i], x[i] = find(p[i]), x[i]+x[p[i]]
    return p[i]
for _ in range(m):
    l, r, d = map(int, input().split())
    pl = find(l)
    pr = find(r)
    if pl == pr and x[r]-x[l] != d:
        print('No')
        break
    else:
        p[pr] = pl 
        x[pr] = x[l] + d - x[r]
else:
    print('Yes')