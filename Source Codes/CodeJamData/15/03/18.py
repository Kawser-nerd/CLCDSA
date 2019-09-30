import sys

rules = [
    [(0, True), (1, True),  (2, True),  (3, True)],
    [(1, True), (0, False), (3, True),  (2, False)],
    [(2, True), (3, False), (0, False), (1, True)],
    [(3, True), (2, True),  (1, False), (0, False)],
]
def red(i, j):
    return (rules[i[0]][j[0]][0], bool(i[1] ^ j[1] ^ rules[i[0]][j[0]][1]))

t = int(sys.stdin.readline().strip())

for i in range(t):
    l, x = sys.stdin.readline().strip().split()
    l = int(l)
    x = int(x)
    if x > 13:
        x = (x - 10) % 4 + 10
    s = sys.stdin.readline().strip()
    ss = []
    for j in range(x):
        for k in range(len(s)):
            if s[k] == 'i':
                ss.append(1)
            elif s[k] == 'j':
                ss.append(2)
            if s[k] == 'k':
                ss.append(3)

    dyns = [(ss[0], True)]
    dyne = [(ss[len(ss) - 1], True)]
    for j in range(2, len(ss) + 1):
        dyns.append(red(dyns[j - 2], (ss[j - 1], True)))
        dyne.append(red((ss[len(ss) - j], True), dyne[j - 2]))

    found = False
    if ((dyns[len(ss) - 1][0] == 0) and (not dyns[len(ss) - 1][1])):
        for p in range(1, len(ss) - 1):
            s1 = dyns[p - 1]
            if s1[0] != 1:
                continue
            for q in range(1, len(ss) - p):
                s3 = dyne[len(ss) - p - q - 1]
                if s3[0] != 3:
                    continue
                found = True
                break
            if found:
                break

    print "Case #%d: %s" % (i + 1, 'YES' if found else 'NO')
