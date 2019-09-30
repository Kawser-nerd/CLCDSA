from sys import stdin

def riadok():
    return map(int, stdin.readline().split())

for cas in range(int(stdin.readline())):
    n = riadok()[0]
    a = []
    for i in range(n):
        s = stdin.readline()
        w = 0
        for j in range(n):
            if s[j] == '1':
                w = j
        a.append(w)

    res = 0
    for i in range(n):
        q = -1
        for j in range(i, n):
            if a[j] <= i:
                q = j
                break
        for j in range(q - 1, i - 1, -1):
            a[j], a[j + 1] = a[j + 1], a[j]
            res += 1

    print "Case #%d: %d" % (cas + 1, res)
