import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from math import sqrt

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

n = ni()
a = [list(li()) for _ in range(n)]
b = [list(li()) for _ in range(n)]

ach = ConvexHull(a)
ach.append(ach[0])
bch = ConvexHull(b)
bch.append(bch[0])

aeuc = []
beuc = []
for i in range(min(len(ach),len(bch))-1):
    aeuc.append(sqrt((ach[i+1][0]-ach[i][0])**2 + (ach[i+1][1]-ach[i][1])**2))
    beuc.append(sqrt((bch[i+1][0]-bch[i][0])**2 + (bch[i+1][1]-bch[i][1])**2))
    
print(sum(beuc)/sum(aeuc))