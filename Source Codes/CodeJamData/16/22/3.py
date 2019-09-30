def solve():
    global ans
    a, b = raw_input().split()
    ans = [10 ** 18, "", ""]
    l = len(a)
    prev = {str(i): str(i - 1) for i in xrange(1, 10)}
    nex = {str(i): str(i + 1) for i in xrange(9)}
    def go(i, eq, ca, cb):
        global ans
        if i == l:
            tdif = abs(int(ca) - int(cb))
            if ans > [tdif, ca, cb]:
                ans = [tdif, ca, cb]
            return
        if eq == 0:
            if a[i] == b[i] == '?':
                go(i + 1, 0, ca + '0', cb + '0')
                go(i + 1, -1, ca + '0', cb + '1')
                go(i + 1, 1, ca + '1', cb + '0')
            elif a[i] == '?':
                go(i + 1, 0, ca + b[i], cb + b[i])
                if b[i] > '0':
                    go(i + 1, -1, ca + prev[b[i]], cb + b[i])
                if b[i] < '9':
                    go(i + 1, 1, ca + nex[b[i]], cb + b[i])
            elif b[i] == '?':
                go(i + 1, 0, ca + a[i], cb + a[i])
                if a[i] > '0':
                    go(i + 1, 1, ca + a[i], cb + prev[a[i]])
                if a[i] < '9':
                    go(i + 1, -1, ca + a[i], cb + nex[a[i]])
            else:
                go(i + 1, cmp(a[i], b[i]), ca + a[i], cb + b[i])
        else:
            na = a[i]
            if a[i] == '?':
                na = '9' if eq == -1 else '0'
            nb = b[i]
            if b[i] == '?':
                nb = '0' if eq == -1 else '9'
            go(i + 1, eq, ca + na, cb + nb)
    go(0, 0, '', '')
    print ans[1], ans[2]

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1),
    solve()
