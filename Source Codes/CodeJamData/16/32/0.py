def f(b,m):
    if m > (1 << (b - 2)):
        return []
    x = [[1 if ((i > j) and (i < (b - 1))) else 0 for i in xrange(b)] for j in xrange(b)]
    m -= 1
    x[0][b-1] = 1
    for i in xrange(1,b-1):
        if (m >> (i-1)) & 1:
            x[i][b-1] = 1
    return x

from sys import stdin

def getint():
    return int(stdin.readline())

def getints():
    return tuple(int(z) for z in stdin.readline().split())

for cn in xrange(1,1 + getint()):
    (b,m) = getints()
    sol = f(b,m)
    if len(sol) == 0:
        output = "IMPOSSIBLE"
    else:
        output = "POSSIBLE\n"+"\n".join("".join(str(k) for k in row) for row in sol)
    print "Case #{}: {}".format(cn, output)
