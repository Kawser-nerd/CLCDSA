import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from math import acos

def ccw(p1,p2,p3):
    return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0])

def ConvexHull(points):
    u = []
    l = []
    points.sort()
    
    for p in points:
        while len(u)>1 and ccw(u[-2], u[-1], p)>=0:
            u.pop()
        while len(l)>1 and ccw(l[-2], l[-1], p)<=0:
            l.pop()
            
        u.append(p)
        l.append(p)
        
    return u + l[-2:0:-1]


def angle(v1, v2):
    inner = v1[0]*v2[0] + v1[1]*v2[1]
    normv1 = (v1[0]**2 + v1[1]**2) ** 0.5
    normv2 = (v2[0]**2 + v2[1]**2) ** 0.5
    
    return acos(inner / (normv1*normv2))

n = ni()
if n == 1:
    print(1)

elif n == 2:
    print(0.5)
    print(0.5)
    
else:
    points = [list(li()) + [i] for i in range(n)]    
    ch = ConvexHull(points)    
    bsc = []
    
    for i in range(len(ch)):
        x1,y1,i1 = ch[i]
        x2,y2,i2 = ch[i-1]
        
        bsc.append((y1-y2, x2-x1))
        
    if len(ch) == 2:
        angles = [1,1]
        
    else:
        angles = [angle(bsc[i], bsc[i-1]) for i in range(len(ch))]
    
    sm = sum(angles)
        
    ans = [0]*n
    for i in range(len(ch)):
        x,y,ind = ch[i-1]
        ans[ind] = angles[i] / sm
        
    for x in ans:
        print(x)