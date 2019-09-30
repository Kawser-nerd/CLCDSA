import numpy
import itertools

MAX=4000
OFFSET=2000

def solve(map, querys):
    querys=set(querys)
    n,m=map.shape
    sol=numpy.zeros((n,m,MAX),numpy.chararray)
    mark=numpy.zeros((n,m,MAX),numpy.bool)

    q=[]
    for row in range(n):
        for col in range(m):
            c=map[row,col]
            if c not in ('+','-'):
                sol[row,col,OFFSET+int(c)]=c
                q.append((row,col,int(c)))

    def neighbours(x,y):
        moves=((0,1),(0,-1),(-1,0),(1,0))
        for move in moves:
            xx=x+move[0]
            yy=y+move[1]
            if xx>=0 and xx<n and yy>=0 and yy<m:
                yield (xx,yy)
        return

    def go(x,y):
        for ne in neighbours(x,y):
            for nne in neighbours(*ne):
                ss=map[ne]+map[nne]
                #print ss
                #print ne,nne
                yield (nne[0], nne[1], ss)
        return

    while querys:
        assert q
        row, col, num = q.pop(0)
        #print row, col
        pos=(row,col,OFFSET+num)
        #print row,col,num,sol[pos]
        mark[pos]=True
        if num in querys:
            querys.remove(num)
        g = go(row, col)
        for nrow, ncol, ss in g:
            nnum = num+int(ss)
            npos=(nrow,ncol,OFFSET+nnum)
            if mark[npos]:
                continue
            nsol = sol[pos]+ss
            if not sol[npos]:
                q.append((nrow,ncol,nnum))
                sol[npos]=nsol
            elif len(sol[npos])>len(nsol) or (len(sol[npos])==len(nsol) and sol[npos]>nsol):
                sol[npos]=nsol
    return sol

def findmin(sol, q):
    row,col,nums = sol.shape
    minsol=None
    for r in range(row):
        for c in range(col):
            s=sol[r,c,OFFSET+q]
            if not s:
                continue
            #print s
            if minsol is None or len(minsol)>len(s) or (len(minsol)==len(s) and minsol>s):
                minsol=s
    return minsol

def docase(f):
    n,m=f.readline().split()
    n=int(n)
    m=int(m)
    map=numpy.zeros((n,n), numpy.character)
    for i in range(n):
        line=f.readline().strip()
        for j in range(len(line)):
            map[i,j]=line[j]
    querys = [int(x) for x in f.readline().split()]
    sol = solve(map, querys)
    for q in querys:
        print findmin(sol,q)
    return

def main(fn):
    f=open(fn)
    n=int(f.readline())
    for i in range(n):
        print 'Case #%d:'%(i+1)
        docase(f)
    return

import sys
main(*sys.argv[1:])



