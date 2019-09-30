import sys

c = int(sys.stdin.readline())

for _ in range(1,c+1):
    n, k, b, t = map(int, sys.stdin.readline().split())
    x = map(int, sys.stdin.readline().split())
    v = map(int, sys.stdin.readline().split())
    c = 0
    s = 0
    for i in range(n-1, -1, -1):
        if x[i] + v[i] * t >= b:
            s += c
            k -= 1
            if k == 0:
                break
        else:
            c += 1
    if k > 0:
        print 'Case #%d: IMPOSSIBLE' % _
    else:
        print 'Case #%d: %d' % (_, s)
