
import sys

def Move(r, c, d, dig):
    global R, C, F, M, best
    c += d
    fall = 0
    while M[r+1][c] == '.':
        d = 0
        fall += 1
        if fall > F:
            return
        r += 1
        if r == R-1:
            best = dig
            return
    if c > 0 and M[r][c-1] == '.':
        if d <= 0:
            Move(r, c, -1, dig)
        if dig+1 < best and M[r+1][c-1] == '#':
            M[r+1][c-1] = '.'
            Move(r, c, 0, dig+1)
            M[r+1][c-1] = '#'
    if c+1 < C and M[r][c+1] == '.':
        if d >= 0:
            Move(r, c, +1, dig)
        if dig+1 < best and M[r+1][c+1] == '#':
            M[r+1][c+1] = '.'
            Move(r, c, 0, dig+1)
            M[r+1][c+1] = '#'
    
def Digging():
    global R, C, F, M, best
    R, C, F = map(int, raw_input().split())
    M = [list(raw_input()) for i in range(R)]
    best = sys.maxint
    Move(0, 0, 0, 0)
    if best < sys.maxint:
        print "Yes", best
    else:
        print "No"

#---------------------------------------------------------------

N = int(raw_input())
for testcase in range(N):
    print "Case #%d:" % (testcase+1),
    Digging()
