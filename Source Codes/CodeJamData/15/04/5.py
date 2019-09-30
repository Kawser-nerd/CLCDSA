import sys

T = int(sys.stdin.readline())
for t in range(T):
    X,R,C = map(int, sys.stdin.readline().split())
    if R > C:
        tmp = C
        C = R
        R = tmp
    if (R*C) % X != 0:
        gabriel = False
    elif X > C:
        gabriel = False
    elif X >= 7:
        gabriel = False
    elif (X+1)/2 > R:
        gabriel = False
    elif (X+1)/2 < R:
        gabriel = True
    elif R == 2:
        if X == 3:
            gabriel = True
        else:
            gabriel = False
    elif R == 3:
        if X == 5:
            if C == 5:
                gabriel = False
            else:
                gabriel = True
        else:
            gabriel = False
    else:
        gabriel = True
    print "Case #%d: %s" % (t+1, "GABRIEL" if gabriel else "RICHARD")
