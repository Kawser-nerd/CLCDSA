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

s = ns()
n = len(s)
ans = 0
for idx, si in enumerate(s):
    if si == 'U':
        ans += (n-idx-1) + 2*idx
    else:
        ans += 2*(n-idx-1) + idx
        
print(ans)