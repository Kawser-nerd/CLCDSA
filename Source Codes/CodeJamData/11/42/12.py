import time, math, operator, os.path
from helper import *

t1 = starttimer()

filename = "B%s.%s"
# 0 for test, 1 for small, 2 for large
is_large = 1

mode_str = '' if is_large == 0 else '-small-attempt0' if is_large == 1 else '-large'
infile = filename % (mode_str, 'in')
outfile = filename % (mode_str, 'out')

# parse input
inf = open(infile, 'r')
outf = open(outfile, 'w')

def getBlades(R, C):
    for k in range(min(R, C), 3-1, -1):
        for i in range(C-k + 1):
            for j in range(R-k + 1):
                yield (i, j, k)

def checkBalanced(blade, w, D):
    centre = (blade[0] + float(blade[2] - 1) / 2, blade[1] + float(blade[2] - 1) / 2)

    s = [0.0, 0.0]
    for i in range(blade[0], blade[0] + blade[2]):
        for j in range(blade[1], blade[1] + blade[2]):
            if i in [blade[0], blade[0] + blade[2] - 1] and j in [blade[1], blade[1] + blade[2] - 1]:
                continue

            s[0] += (D + w[j][i]) * (i - centre[0])
            s[1] += (D + w[j][i]) * (j - centre[1])

    if abs(s[0]) < 1e-9 and abs(s[1]) < 1e-9:
        return True
    else:
        return False

try:
    T = readI(inf)
    
    for case in range(1, T+1):
        R, C, D = readIA(inf)
        w = [map(int, readL(inf)) for i in range(R)]

        print w

        possible = False
        output = -1
        for blade in getBlades(R, C):
            if checkBalanced(blade, w, D):
                possible = True
                output = blade[2]
                break

        print possible, output
        if not possible:
            outf.write("Case #%d: %s\n" % (case, 'IMPOSSIBLE'))
        else:
            outf.write("Case #%d: %s\n" % (case, output))
    
finally:
    inf.close()
    outf.close()

endtimer(t1)
