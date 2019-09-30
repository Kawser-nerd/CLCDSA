import sys
import math

ALOT = 10**15

def trythis(D, PVs, t):
    leftmost = -ALOT*10
    for P, V in PVs:
        next = max(P-t, leftmost+D)
        next += (V-1) * D
        if next>P+t:
            return False
        leftmost = next
    return True

def solve(D, PVs):
    mx = ALOT
    mn = 0
    while mx>mn:
        mid = (mx + mn) // 2
        if trythis(D, PVs, mid):
            mx = mid
        else:
            mn = mid+1
    return mx        

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    C = int(line[0])
    D = int(line[1])
    PVs = []
    for i in range(C):
        line = readline().split()
        PVs.append((int(line[0])*2, int(line[1])))
    res = solve(D*2, PVs)
    return str(res*0.5)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
