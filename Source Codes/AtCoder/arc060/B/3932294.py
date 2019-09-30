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

from math import floor, sqrt

def digit_sum(num:int, base:int) -> int:

    if num < base:
        return num
    else:
        return digit_sum(int(num/base), base) + (num % base)
    
n = ni()
s = ni()

root = floor(sqrt(n))
ans = float("inf")

# 3???
for p in range(2, root+1):
    ds = digit_sum(n,p)
    if ds == s:
        ans = min(ans, p)
        

# 2?
for a in range(1,root+2):
    p = (n-s+a) / a
    b = s - a
    if p == int(p) and 0 < a < p and 0 <= b < p:
        ans = min(ans, int(p))

# 1?
if n == s:
    ans = min(ans, n+1)
    
print(-1) if ans == float("inf") else print(ans)