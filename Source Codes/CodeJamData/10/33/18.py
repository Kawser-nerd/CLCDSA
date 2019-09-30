#! /usr/bin/env python
import sys, re
# some reading functions
getline = lambda f: f.readline().strip()
gettoken = lambda f: re.split("\s+", getline(f))
getint = lambda f: int(getline(f))
getints = lambda f: map(int, gettoken(f))
getintsb = lambda f, b: map(lambda x: int(x, b), gettoken(f))

# number theory / combinatorics
product = lambda l: reduce(lambda x,y: x*y, l) if l else 1
factorial = lambda n: product(xrange(n, 1, -1))
nPr = lambda n, r: product(xrange(n,n-r,-1))
nCr = lambda n, r: nPr(n, r) / factorial(r)
nMr = lambda l: factorial(sum(l)) / product(map(factorial,l))
gcd = lambda x,y: gcd(y, x%y) if y != 0 else x
lcm = lambda x,y: x * y / gcd(x, y)
def gcd2(a, b):
    if b == 0: return (a, 1, 0)
    (d,x,y) = gcd2(b, a % b)
    return (d, y, x - a / b * y)

def markblock(b, m, n, s):
    for i in xrange(s):
        c = b[m + i]
        for j in xrange(s):
            c[n + j] = 2
    

def findblock(b, m, n, s):
    if m + s > len(b) or n + s > len(b[0]): return False
    
    even = s % 2 == 0
    a = b[m][n]

    for i in xrange(s):
        c = b[m + i]
        for j in xrange(s):
            v = c[n + j]
            #print i, j, v
            if v == 2: return False
            if i == 0 and j == 0: continue
            if v == a: return False
            
            a = not a#0 if a == 1 else 0
        if even: a = not a
    return True

if __name__ == "__main__":
    f = open(sys.argv[1]) # open file

    [CASES] = getints(f)
    for cases in xrange(1,CASES+1): # loop over cases
        ans = 0
        # main
        M, N = getints(f)
        board = []
        for i in xrange(M):
            rows = getintsb(f, 16)
            rowb = reduce(lambda x, y: (x << 4) | y, rows)
            row = [0] * N
            for j in xrange(N-1, -1, -1):
                row[j] = rowb & 1
                rowb >>= 1            
            board.append(row)

        S = s = M if M < N else N
        anss = [0]*(s + 1)

        #print board
        #print findblock(board, 11, 0, 4)
        #print findblock(board, 11, 12, 4)
        #print board[11][0], board[11][1]
        #"""
        while s > 0:
            for i in xrange(M):
                for j in xrange(N):
                    k = findblock(board, i, j, s)
                    if k: 
                        anss[s] += 1
                        markblock(board, i, j, s)
            s -= 1
        
        anss = filter(lambda (i, x): x != 0, zip(xrange(S + 1), anss))
        #print anss
        #"""

        ans = len(anss)
        

        # main
        print "Case #%d: %d"%( cases, ans ) # answer output

        for (i, x) in reversed(anss):
            print "%d %d" %(i, x)
