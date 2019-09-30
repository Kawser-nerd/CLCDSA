from __future__ import print_function, division
from future_builtins import filter, map, zip
from fractions import *
from math import *
TOTAL = int(raw_input())

def Ps(p,q):
    x=0
    y=0
    dx=0
    if p>0:
        dx=1
    elif p < 0:
        dx=-1
    dy=0
    if q>0:
        dy=1
    elif q<0:
        dy=-1
    if dy==0:
        while True:
            x=x+dx
            yield (dx,0)
    while True:
        yy=y if dy<0 else y+dy
        xx=X(p,q,yy)
        #print(xx,yy)
        fx=floor(xx)
        if fx==xx:
            if dx < 0:
                fx-=1
            while True:
                x+=dx
                if x != fx:
                    yield (dx,0)
                else:
                    break
            y+=dy
            yield (dx,dy)
        else:
            while x!=fx:
                x+=dx
                yield (dx,0)
            y+=dy
            yield (0,dy)

def dis(x,y):
    return x*x+y*y

def X(p,q,y):
    return p*(y-0.5)/q+0.5
"""
k=0
for i, j in Ps(-3,1):
    if k>10:
        break
    print("# ", i, j)
    k+=1
TOTAL=0
"""
for case in xrange(1,TOTAL+1):
    H, W, D=map(int, raw_input().split())
    T=[raw_input() for l in xrange(0,H)]
    #if case != 7:
    #    continue
    x0=0
    y0=0
    for i in xrange(0,H):
        y0=T[i].find('X')
        if y0!=-1:
            x0=i
            break
    D2=D*D
    count=0
    for i in xrange(-D,D+1):
        for j in xrange(-D, D+1):
            if abs(gcd(i,j)) != 1 or dis(i,j) > D2 :
                continue
            #print("i j ", i, j)
            rx=1
            ry=1
            x,y=x0,y0
            x1,y1=0,0
            for dx, dy in Ps(i,j):
                #print(dx, dy)
                x1=x1+dx
                y1=y1+dy
                if dis(x1,y1)>D2:
                    break
                nx=x+rx*dx
                ny=y+ry*dy
                if T[nx][ny] == '#':
                    if dx != 0 and dy!= 0:
                        if T[nx][y]!='#' and T[x][ny]!='#':
                            break
                        if T[nx][y]=='#':
                            rx=-rx
                        else:
                            x=nx
                        if T[x][ny]=='#':
                            ry=-ry
                        else:
                            y=ny
                    elif dx != 0:
                        rx=-rx
                    elif dy != 0:
                        ry=-ry
                else:
                    x=nx
                    y=ny
                if (i==0 or x1 % i==0) and (j == 0 or y1 % j == 0) and x0==x and y0==y:
                    count+=1
                    #print('(', x1, y1, ')')
                    break
    print('Case #{0}: {1}'.format(case,count))

