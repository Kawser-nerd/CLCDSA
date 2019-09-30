tc = int(input().strip())

for t in range(tc):
    r, c = [int(x) for x in input().split()]

    m = r * [[]]
    for i in range(r):
        a = input()
        m[i] = [a[j] for j in range(c)]

    result = dict()

    for i in range(r):
        if m[i].count('.') == c:
            continue
        lb = True
        rb = True
        for j in range(c):
            if lb and m[i][j] != '.':
                result.setdefault((i,j), []).append("<")
                lb = False
            if rb and m[i][c-1-j] != '.':
                result.setdefault((i,c-1-j), []).append(">")
                rb = False

    for j in range(c):
        if [m[i][j] for i in range(r)].count('.') == r:
            continue
        tb = True
        bb = True
        for i in range(r):
            if tb and m[i][j] != '.':
                result.setdefault((i,j), []).append("^")
                tb = False
            if bb and m[r-1-i][j] != '.':
                result.setdefault((r-1-i,j), []).append("v")
                bb = False

    p = True
    s = 0

    for k, v in result.items():
        if len(v) == 4:
            p = False
        else:
            if m[k[0]][k[1]] in v:
                s += 1

    if not p:
        print("Case #%d: IMPOSSIBLE" % (t+1))
    else:
        print("Case #%d: %d" % (t+1, s))

