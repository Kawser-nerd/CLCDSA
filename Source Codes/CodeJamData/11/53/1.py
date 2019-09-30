import sys
import math
sys.setrecursionlimit(11000)
MOD = 1000003

def color(nbh, colors, x, clr):
    colors[x] = clr
    for y in nbh[x]:
        if colors[y] is None:
            color(nbh, colors, y, clr)

def solve(m,n,mmm):
    nvert = m*n
    edges = []
    neighbours = [[] for i in range(nvert)]
    for i in range(m):
        for j in range(n):
            ch = mmm[i][j]
            if ch=='|':
                di = 1
                dj = 0
            if ch=='-':
                di = 0
                dj = 1
            if ch=='/':
                di = 1
                dj = -1
            if ch=='\\':
                di = 1
                dj = 1
            i1 = (i+di)%m
            i2 = (i-di)%m 
            j1 = (j+dj)%n
            j2 = (j-dj)%n
            c1 = i1*n + j1
            c2 = i2*n + j2
            edges.append((c1, c2))
            neighbours[c1].append(c2)
            neighbours[c2].append(c1)
    colors = [None]*nvert
    clr = 0
    for i in range(nvert):
        if colors[i] is None:
            color(neighbours, colors, i, clr)
            clr += 1
    cedges = [0]*clr
    cvert = [0]*clr
    for i in range(nvert):
        cvert[colors[i]] += 1
    for x, y in edges:
        cedges[colors[x]] += 1
    res = 1
    for i in range(clr):
        if cedges[i]!=cvert[i]:
            return 0
        res = (res*2)%MOD
    return res
    
    
    

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    m = int(line[0])
    n = int(line[1])
    mmm = []
    for i in range(m):
        mmm.append(readline())
    res = solve(m,n,mmm)
    return str(res)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
