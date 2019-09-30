# -*- coding: utf-8 -*-

from sys import stdin

def main():
    n, k = map(int, stdin.readline().strip().split())
    
    stocks = [map(int, stdin.readline().strip().split()) for _ in xrange(n)]
    def edge(i, j):
        #v = cmp(stocks[i][0], stocks[j][0])
        #if v == 0:
        #    return True
        return all(cmp(a, b)==-1 for a,b in zip(stocks[i], stocks[j]))
    c = [[int(edge(i, j)) for j in xrange(n)] for i in xrange(n)]
    f = [[0]*n for j in xrange(n)]
    lm = [False]*n
    rm = [False]*n
    def dfs(x):
        for y in xrange(n):
            if c[x][y] - f[x][y] > 0 and not m[y+n]:
                m[y+n] = True
                if not rm[y]:
                    f[x][y] = 1
                    rm[y] = True
                    return True
                for z in xrange(n):
                    if f[z][y] > 0 and not  m[z]:
                        m[z] = True
                        if dfs(z):
                            f[z][y] = 0
                            f[x][y] = 1
                            return True
        return False
    while True:
        m = [False]*(2*n)
        for i in xrange(n):
            if not lm[i] and not m[i]:
                m[i] = True
                if dfs(i):
                    lm[i] = True
                    break
        else:
            break
    res = n - sum(map(int, lm))
    
    return str(res)

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())