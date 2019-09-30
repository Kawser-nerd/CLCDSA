import sys
import math

def solve(N, diamond):
    best1 = N
    for i in range(-N+1, N):
        ok = True
        for x in range(N):
            for y in range(N):
                x0 = y+i
                y0 = x-i
                if x0>=0 and x0<N and y0>=0 and y0<N:
                    if diamond[x0][y0] != diamond[x][y]:
                        ok = False
                        break
            if not ok:
                break
        if not ok:
            continue
        par = i%2
        qual = abs(i)
        if best1>qual:
            best1 = qual
            
    best2 = N
    for i in range(-N+1, N):
        ok = True
        for x in range(N):
            for y in range(N):
                x0 = N-1-y-i
                y0 = N-1-x-i
                if x0>=0 and x0<N and y0>=0 and y0<N:
                    if diamond[x0][y0] != diamond[x][y]:
                        ok = False
                        break
            if not ok:
                break
        if not ok:
            continue
        par = i%2
        qual = abs(i)
        if best2>qual:
            best2 = qual
    
    new_size = N + best1 + best2
    return new_size**2 - N**2

def do_test(input):
    line = input.readline().strip(' \r\n\t').split()
    N = int(line[0])
    diamond = [[0] * N for i in range(N)]
    lines = [input.readline() for i in range(2*N-1)]
    for i in range(N):
        for j in range(N):
            diamond[i][j] = int(lines[i+j][N-1+i-j])
    res = solve(N, diamond)
    return str(res)

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()

        
