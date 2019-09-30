import sys, string
from copy import copy, deepcopy
import gmpy
import time
from fractions import gcd

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def printmaze(M):
    for c in M:
        print "".join(c)
    
def maze(x, n, m):
    M = []
    for i in range(n):
        col = []
        for j in range(m):
            pos = j + i * m
            bit = x & (1 << pos)
            col += '*' if bit else '.'
        M.append(col)
    return M

def score(M):
    n = len(M)
    m = len(M[0])
    for i in range(n):
        for j in range(m):
            if M[i][j] != '.':
                M[i][j] = 'O'
                break
        for j in range(m-1,-1,-1):
            if M[i][j] != '.':
                M[i][j] = 'O'
                break
    for j in range(m):
        for i in range(n):
            if M[i][j] != '.':
                M[i][j] = 'O'
                break
        for i in range(n-1,-1,-1):
            if M[i][j] != '.':
                M[i][j] = 'O'
                break
    s = 0
    for j in range(m):
        for i in range(n):
            if M[i][j] == '*':
                s += 1

    #~ printmaze(M)
    #~ print s
    return s

    
for t in range(T):
    N,M,K = readlist()
    
    mz = [
        ['.', '*', '*', '.', '.'],
        ['*', '*', '*', '*', '.'],
        ['.', '*', '*', '.', '.'],
        ['.', '.', '.', '.', '.']];
    #~ printmaze(mz)
    #~ print score(mz)

    #~ continue
    print >> sys.stderr, t
    print ("Case #%d:" % (t+1)),
    
    best = -1
    for i in range(1 << (N*M)):
        #~ print i, gmpy.popcount(i)
        if gmpy.popcount(i) == K:
            mz = maze(i, N, M)
            s = score(mz)
            #~ print i
            if s > best:
                #~ printmaze(mz)
                #~ print s
                best = s
    print K-best
