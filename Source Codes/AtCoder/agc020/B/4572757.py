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

k = ni()
a = list(li())

if a[-1] != 2:
    print(-1)
    
else:
    lower = 2
    upper = 3
    exist = True
    for ai in a[-2::-1]:
        if lower%ai > 0 and upper%ai > 0 and lower//ai == upper//ai:
            exist = False
            print(-1)
            break
        
        lower = -(-lower//ai) * ai
        upper = (upper//ai) * ai + (ai-1)
        
    if exist:
        print(lower, upper)