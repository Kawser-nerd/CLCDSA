import sys
import math

def solve(X, S, R, t, wL):
    X0 = X - sum(L for w, L in wL)
    wL.append((0, X0))
    wL.sort()
    res = 0
    for w, L in wL:
        rT = min(L / (w + R), t)
        t -= rT
        res += rT
        wT = (L - (w + R) * rT) / (w + S)
        res += wT
    return res    
        

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    X = float(line[0])
    S = float(line[1])
    R = float(line[2])
    t = float(line[3])
    n = int(line[4])
    wL = []
    for i in range(n):
        line = readline().split()
        wL.append((float(line[2]), float(line[1]) - float(line[0])))
        
    res = solve(X, S, R, t, wL)
    return str(res)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
