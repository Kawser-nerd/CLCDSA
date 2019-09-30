from sys import stdin

def riadok():
    return map(int, stdin.readline().split())

for cas in range(int(stdin.readline())):
    n, m = riadok()
    root = {}
    a = [stdin.readline()[:-1] for x in range(n)]
    b = [stdin.readline()[:-1] for x in range(m)]
    for i in range(n):
        q = a[i].split('/')[1:]
        act = root
        for x in q:
            if x not in act:
                act[x] = {}
            act = act[x]

    res = 0
    for i in range(m):
        q = b[i].split('/')[1:]
        act = root
        for x in q:
            if x not in act:
                res += 1
                act[x] = {}
            act = act[x]

    print "Case #%d: %d" % (cas + 1, res)
