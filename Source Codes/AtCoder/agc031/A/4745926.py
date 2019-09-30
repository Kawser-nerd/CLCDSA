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

from collections import Counter

n = ni()
s = ns()

cnt = Counter(s)

ans = 1
mod = 10**9+7

for k,v in cnt.items():
    ans *= (v+1)
    ans %= mod
    
ans -= 1
if ans < 0:
    ans += mod
    
print(ans)