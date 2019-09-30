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

one2n = sum([i for i in range(1, n+1)])

ok = True

if sum(a) % one2n > 0:
    ok = False
    
if ok:
    b = a + [a[0]]
    end = 0
    kire = sum(a) // one2n
    for idx in range(n):
        dif = b[idx+1] - b[idx]
        if (kire-dif) % n > 0:
            ok = False
            break
        
        elif (kire-dif)//n < 0:
            ok = False
            break
        
        end += (kire-dif) // n
        
    if end != kire:
        ok = False
        
print("YES") if ok else print("NO")