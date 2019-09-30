from sys import stdin

def riadok():
    return map(int, stdin.readline().split())

for cas in range(int(stdin.readline())):
    n, k, b, t = riadok()
    x = riadok()
    v = riadok()
    res = []
    for i in range(n):
        cnt = 0
        for j in range(i + 1, n):
            if b - x[j] > t * v[j]: cnt += 1
        if b - x[i] <= t * v[i]:
            res.append(cnt)
    s = "IMPOSSIBLE"
    if len(res) >= k:
        res.sort()
        s = "%d" % (sum(res[:k]))
    print "Case #%d: %s" % (cas + 1, s)
