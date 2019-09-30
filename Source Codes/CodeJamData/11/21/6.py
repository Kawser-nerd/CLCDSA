import sys
NAME = None
#NAME = "-small-attempt"
#NAME = "-large"

def calc_wp(a, num, ex = -1):
    total = 0
    win = 0
    for i in range(len(a)):
        if i == ex:
            continue
        if a[num][i] == '1':
            win += 1
        if a[num][i] != '.':
            total += 1
    return win / total

def calc_owp(a, num):
    n = len(a)
    res = 0
    cnt = 0
    for i in range(n):
        if a[num][i] != '.':
            res += calc_wp(a, i, num)
            cnt += 1
    return res / cnt

def calc_oowp(a, num, owp):
    n = len(a)
    res = 0
    cnt = 0
    for i in range(n):
        if a[num][i] != '.':
            res += owp[i]
            cnt += 1
    return res / cnt

def getMagicWord():
    n = nextToken(int)
    a = []
    for i in range(n):
        a.append(nextToken())

    wp = [0] * n
    owp = [0] * n
    oowp = [0] * n
    for i in range(n):
        wp[i] = calc_wp(a, i)
        owp[i] = calc_owp(a, i)

    res = [0] * n
    for i in range(n):
        oowp[i] = calc_oowp(a, i, owp)
    for i in range(n):
        res[i] = wp[i] * 0.25 + owp[i] * 0.5 + oowp[i] * 0.25

    res = "\n".join(map(lambda x: "%.8f" % x, res))
    return '\n' + res

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
