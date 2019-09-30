import sys
rl = lambda: sys.stdin.readline().strip()

def buf(str, mx):
    return list(str + " " * (mx - len(str)))

def transpose(s):
    ret = [[" "] * len(s) for i in range(len(s[0]))]
    for i in range(len(s)):
        for j in range(len(s[i])):
            ret[j][i] = s[i][j]
    return ret

def diff(a, b):
    for aa, bb in zip(a, b):
        if (aa != " " and bb != " " and aa != bb):
            return True
    return False

def can_fold(s, middle):
    for i in range(middle,len(s)):
        j = middle - (i - middle)
        if j < 0: continue
        if diff(s[i], s[j]):
            return False
    return True

def s(n):
    return sum(range(n)) * 2 + n

t = int(rl())
for cc in range(t):
    k = int(rl())
    dia = [buf(sys.stdin.readline().rstrip("\n"), k*2-1) for i in range(k*2-1)]
    trans = transpose(dia)
    ret = 987654321
    for middle in range(len(dia)):
        if can_fold(dia, middle):
            for center in range(len(dia)):
                if can_fold(trans, center):
                    height = max(len(dia) - middle - 1, middle ) * 2 + 1
                    actual_center = ((height + 1) / 2 - k) + center
                    width = max(height - actual_center - 1, actual_center) * 2 + 1
                    """
                    print ("can fold middle %d center %d height %d width %d" %
                           (middle, center, height, width))
                           """
                    cand = max(height, width)
                    ret = min(ret, cand)
    l = (ret + 1) / 2
    ret = s(l) - s(k)
    print "Case #%d: %d" % (cc+1, ret)
