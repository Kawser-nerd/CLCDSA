# -*- coding: utf-8 -*-

'''
http://code.google.com/codejam/contest/dashboard?c=544101#s=p0
'''

import sys

def lin(): return sys.stdin.readline()
def ints(): return [int(s) for s in lin().split()]

T = int(lin())

# |, -, \, /
dx = [0, 1, 1, 1]
dy = [1, 0, 1, -1]

global S

def line(x, y, K):
    #global dx, dy
    for d in range(4):
        ok = True
        for i in range(K):
            xx = x+i*dx[d]
            yy = y+i*dy[d]
            if not (xx<len(S) and yy<len(S[x]) and S[xx][yy]==S[x][y]):
                ok = False
                break
        if ok:
            return True
    return False

for casenum in range(T):
    (N, K) = ints()
    #print (N,K)
    s = [lin().strip() for i in range(N)]
    t = []
    for l in s:
        ll = [c for c in l]
        #print '#%s#' % l
        for i in range(len(l)-2,-1,-1):
            k=i+1
            while k<len(l) and ll[k]=='.':
                ll[k] = ll[k-1]
                ll[k-1] = '.'
                k += 1
        l = ''.join(ll)
        t.append(l)
    S = t
#     for l in S:
#         print '$%s$' % l
    ok = {'B': False, 'R': False}
    for x in range(N):
        for y in range(N):
            if S[x][y] in ('R', 'B') and line(x, y, K):
                ok[S[x][y]] = True
    #print ok

    print "Case #%d: %s" % (casenum+1,
                            'Neither' if not ok['R'] and not ok['B']
                            else 'Both' if ok['R'] and ok['B']
                            else 'Red' if ok['R']
                            else 'Blue')
