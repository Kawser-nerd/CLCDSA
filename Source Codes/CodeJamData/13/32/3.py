from sys import stdin
def solve():
    x, y = map(int, stdin.readline().split())
    z = abs(x) + abs(y)
    t = i = 0
    for i in xrange(3000):
        t = t + i
        if t % 2 == z % 2 and t >= z:
            break
    ans = []
    f = lambda a: abs(a[0]) + abs(a[1])
    w = "WESN"
    n = 0
    for j in xrange(i, 0, -1):
        c = [(x+j, y), (x-j, y), (x, y+j), (x, y-j)]
        k = min(map(f, c))
        for n in xrange(4):
            if f(c[n]) == k:
                break
        x, y = c[n]
        ans.append(w[n])
    return ''.join(reversed(ans))
N = int(stdin.readline())
for i in xrange(N):
    print "Case #%d: %s" % (i+1, solve())
