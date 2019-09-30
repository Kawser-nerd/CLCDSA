# May, 23, 2010
# Round 1C
# "Load Testing"

from time import time
from math import log

#inpath = "B-sample.in"
inpath = "B-large.in"
#inpath = 'B-small-attempt0.in'
outpath = "B.out"

fin = open(inpath)
fout = open(outpath, 'w')

def Testing(L, P, C):
    t = log(float(P)/L, C)
    i = 0
    while t > 2**i:
        i += 1
    return i

timestart = time()
T = int(fin.readline())
for case in range(1, T+1):
    L, P, C = map(int, fin.readline().split())
    result = Testing(L, P, C)
    print result
    fout.write("Case #%d: %s\n" % (case, result))

fin.close()
fout.close()
print "\nTime: %.4f" % (time() - timestart)
