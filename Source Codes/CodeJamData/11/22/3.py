import sys
NAME = None
#NAME = "-small-attempt"
#NAME = "-large"

def ok(points, time, D):
    prev = None

    for p in points:
        x, cnt = p[0], p[1]
        minX = x - time
        if prev is not None:
            minX = max(minX, prev + D)
        next = minX + D * (cnt - 1)
        if abs(x - next) > time:
            return False
        prev = next
    return True

def getMagicWord():
    numPoints = nextToken(int)
    D = nextToken(int) * 2

    p = []
    pMin = 1000000
    pMax = -pMin
    n = 0
    for i in range(numPoints):
        x = nextToken(int) * 2
        cnt = nextToken(int)
        p.append( (x, cnt) )

    p.sort(key = lambda x: x[0])

    L, R = -1, 10 ** 14

    while R - L > 1:
        K = (L + R) // 2
        if ok(p, K, D):
            R = K
        else:
            L = K

    return "%.1f" % (R / 2)
 
################################################
################################################
def nextToken(func = None):
    res = ""
    while fin:
        c = fin.read(1)
        if c.isspace():
            break
        res += c
    if func:
        return func(res)
    else:
        return res

def nextLine():
    if fin:
        return fin.readline()
    else:
        return ""

if NAME:
    fin, fout = open(NAME + ".in", "r"), open(NAME + ".out", "w")
else:
    fin, fout = sys.stdin, sys.stdout

#########################
for testNum in range(nextToken(int)):
    print("Case #%d: %s" % (testNum + 1, getMagicWord()))
