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

def digit_sum(num:int, base:int) -> int:

    if num < base:
        return num
    else:
        return digit_sum(int(num/base), base) + (num % base)

n = ni()
s = ni()

ans = -1

if s > n:
    ans = -1
  
elif s == n:
    ans = n+1
    
else:
    base = 2
    exist = False
    while base*base <= n:
        ds = digit_sum(n,base)
        if ds == s:
            ans = base
            exist = True
            break
        
        base += 1
        
    
    if not exist:
        for p in range(base,0,-1):
            if (n-s+p)%p == 0 and s-p >= 0:
                b = (n-s+p)//p
                if b > p and b > s-p:
                    ans = b
                    exist = True
                    break
            
print(ans)