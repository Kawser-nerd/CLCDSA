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

from math import sin, pi

def ev(a,b,c,t):
    return a*t + b*sin(pi*c*t)

a,b,c = li()
prev = 0
while prev+(1/2*c) < (100-b)/a:
    prev += 1/(2*c)
    
cur = prev + 1/(2*c)
    
while (100-ev(a,b,c,prev))*(100-ev(a,b,c,cur)) > 0:
    prev += 1/(2*c)
    cur += 1/(2*c)
    
left = prev
right = cur
pl = True
if ev(a,b,c,left) < ev(a,b,c,right):
    pl = True
else:
    pl = False
    
eps = 1/(10**10)

while right - left > eps:
    mid = (right+left) / 2
    if ev(a,b,c,mid) > 100:
        if pl:
            right = mid
        else:
            left = mid
            
    else:
        if pl:
            left = mid
        else:
            right = mid
            
print(mid)