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

n = ni()
a = list(li())

def judge(a: list, n: int):
    for ai in a:
        if ai >= n:
            return True
        
    return False

ans = 0
while judge(a, n):
    amax = max(a)
    argmax = a.index(amax)
    x = -( -(amax-(n-1)) // n)
    ans += x
    
    nex = [ai + x if i != argmax else ai - n*x for (i,ai) in enumerate(a)]
    a = nex
    
print(ans)