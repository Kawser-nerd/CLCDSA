# -*- coding: utf-8 -*-

import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    N, W, L = map(int, fin.readline().split())
    Rl = list(map(int, fin.readline().split()))
    R = []
    for i, r in enumerate(Rl):
        R.append((r, i))
    R.sort(reverse=True)

    x = W   # Right edge of column
    rs = 0  # Top of row
    re = -1000000  # Bottom of row
    y = 0   # Top edge of remaining space in column
    p = []
    for r, i in R:
        if re - y >= r*2 and L - y >= r:
            # Stack on column
            p.append((i, x-r, y+r))
            y += r*2
        elif W - x >= r*2:
            # New column
            x += r*2
            pos = max(0, rs+r)
            p.append((i, x-r, pos))
            y = pos+r
        elif L - re >= r:
            # New row
            rs = max(re, -r)    # minimum y pos
            re = rs + 2*r
            p.append((i, 0, rs+r))
            x = r
            y = re
            # Will start a new column directly after this
        else:
            print("IMPOSSIBLE")
            break


    p.sort()
    print(p, file=sys.stderr)
    result = ""
    for i, x, y in p:
        if x > W or y > L:
            print("ERROR")

        result += "%d %d " % (x, y)


    print("Case #%d: %s" % (case, result.strip()))

