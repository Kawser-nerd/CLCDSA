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

dist = 0
far = 1
for i in range(2,n+1):
    print("? 1 {}".format(i), flush=True)
    nex_dist = ni()
    if dist < nex_dist:
        dist = nex_dist
        far = i
        
ans = 0
for j in range(1,n+1):
    if j == far:
        continue
    
    print("? {} {}".format(far, j), flush=True)
    nex = ni()
    ans = max(ans, nex)
    
print("! {}".format(ans),flush=True)