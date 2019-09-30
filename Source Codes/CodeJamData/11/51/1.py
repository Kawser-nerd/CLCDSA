import sys
import math

def solve(W, L, U, G):
    area = 0
    for i in range(len(L)-1):
        area -= (L[i+1][0] - L[i][0]) * (L[i+1][1] + L[i][1])
    for i in range(len(U)-1):
        area += (U[i+1][0] - U[i][0]) * (U[i+1][1] + U[i][1])
    part = area*1./G
    cuts = []
    iL = 0
    iU = 0
    w = U[0][1] - L[0][1]
    a = 0
    x = 0
    while True:
        sL = (L[iL+1][1] - L[iL][1])*1./(L[iL+1][0] - L[iL][0])
        sU = (U[iU+1][1] - U[iU][1])*1./(U[iU+1][0] - U[iU][0])
        s = sU - sL
        nxL = L[iL+1][0]
        nxU = U[iU+1][0]
        nx = min(nxL, nxU)
        na = 2*w*(nx - x) + s * (nx - x) * (nx - x)
        #print '*', iL, iU, a
        if a+na>=part:
            dx = (part-a)*1./(w + math.sqrt(w*w + (part - a)*s))
            x += dx
            a += 2*w*dx + s*dx*dx
            #print 'a=', a, part, area
            cuts.append(x)
            w += s * dx
            a = 0
        else:
            dx = nx - x
            a += 2*w*dx + s*dx*dx
            x = nx
            w += s*dx
            if nx==nxL:
                iL += 1
            if nx==nxU:
                iU += 1
            if iL>=len(L)-1:
                break
            if iU>=len(U)-1:
                break
    #print w, a, x, W
    return cuts[:G-1]

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    W = int(line[0])
    Ln = int(line[1])
    Un = int(line[2])
    G = int(line[3])
    L = []
    for i in range(Ln):
        line = readline().split()
        x = int(line[0])
        y = int(line[1])
        L.append((x,y))
    U = []
    for i in range(Un):
        line = readline().split()
        x = int(line[0])
        y = int(line[1])
        U.append((x,y))
        
    res = solve(W, L, U, G)
    return res

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d:' % (test+1,)
    for x in answer:
        print x
    sys.stdout.flush()
    
