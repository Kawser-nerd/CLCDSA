import sys

def solve(x, r, c):
    if (r * c) % x != 0:
        return True
    if (r < x) and (c < x):
        return True
    if min(r, c) * 2 + 1 <= x:
        return True
    if x < 4:
        return False
    if x > 6:
        return True
    if x == 4:
        if min(r,c) <= 2:
            return True
        else:
            return False
    if x == 5:
        if (min(r,c) == 3) and (max(r,c) == 5):
            return True
        else:
            return False
    if x == 6:
        if min(r,c) == 3:
            return True
        else:
            return False

t = int(sys.stdin.readline().strip())

for i in range(t):
    x, r, c = sys.stdin.readline().strip().split()
    x = int(x)
    r = int(r)
    c = int(c)
    print "Case #%d: %s" % (i + 1, "RICHARD" if solve(x, r, c) else "GABRIEL")
