import math

T = int(raw_input())

for t in range(1, T+1):
    L, P, C = map(int, raw_input().split())
    x = 1
    y = float(P)
    while math.ceil(y / C) > L:
        x += 1
        y = math.ceil(y / C)
    if x != 0:
        x = math.log(x, 2)
    print "Case #%d: %d" % (t, math.ceil(x))
