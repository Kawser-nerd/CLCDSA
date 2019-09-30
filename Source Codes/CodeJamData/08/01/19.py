import sys

def foo2(ss, qs):
    m = len(ss)
    n = len(qs)
    ss2 = {}
    for i, x in enumerate(ss):
        ss2[x] = i

    res = [[-1] * len(ss) for i in range(n)]
    qs = qs[::-1]

    t = ss2.get(qs[0], -1)
    for i in range(m):
        if i == t:
            continue
        res[0][i] = 0

    for i in range(1, n):
        t = ss2.get(qs[i], -1)
        for j in range(m):
            if j == t:
                continue
            for k in range(m):
                if res[i-1][k] == -1:
                    continue
                nr = res[i-1][k]
                if j != k:
                    nr += 1
                if res[i][j] == -1 or res[i][j] > nr:
                    res[i][j] = nr

    return min([x for x in res[n-1] if x != -1])


    


def foo(n, ifile):
    s = int(ifile.readline().strip())
    ss = [None] * s
    for i in range(s):
        ss[i] = ifile.readline()

    q = int(ifile.readline().strip())
    qs = [None] * q
    for i in range(q):
        qs[i] = ifile.readline()

    if len(qs) == 0:
        res = 0
    else:
        res = foo2(ss, qs)
    print 'Case #%i: %i' % (n+1, res)

def main(ifile):
    line = ifile.readline()
    x = int(line)
    for i in range(x):
        foo(i, ifile)

if __name__ == '__main__':
    main(sys.stdin)
