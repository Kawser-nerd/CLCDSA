n, q = map(int, input().split())
ws = [tuple(map(int, input().split())) for _ in range(q)]

union = {(x, z):(x, z) for x in range(1, n+1) for z in 'oe'}
def root(n):
    if union[n] == n:
        return n
    union[n] = root(union[n])
    return union[n]

for w, x, y, z in ws:
    if w == 2:
        print('YES' if root((x, 'e')) == root((y, 'e')) else 'NO')
    elif z % 2 == 0:
        rex, rey = sorted([root((x, 'e')), root((y, 'e'))])
        union[rex] = rey
        rox, roy = sorted([root((x, 'o')), root((y, 'o'))])
        union[rox] = roy
    else:
        reox, reoy = sorted([root((x, 'e')), root((y, 'o'))])
        union[reox] = reoy
        roex, roey = sorted([root((x, 'o')), root((y, 'e'))])
        union[roex] = roey