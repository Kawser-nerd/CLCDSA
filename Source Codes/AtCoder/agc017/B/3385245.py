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

n,a,b,c,d = li()

exist = False

for m in range(n-1):
    if -d*m+c*(n-1-m) <= b-a <= -c*m+d*(n-1-m):
        exist = True
        
if exist:
    print("YES")
else:
    print("NO")