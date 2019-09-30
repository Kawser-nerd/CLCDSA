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

from itertools import accumulate

n = ni()
a = list(li())
a.sort()
acc = list(accumulate(a))



ans = 0
for ai, acci in zip(a[-1:0:-1], acc[-2::-1]):
    if 2*acci >= ai:
        ans += 1
    else:
        break
        
        
print(ans+1)