import sys
stdin = sys.stdin

def li(): return [int(x) for x in stdin.readline().split()]
def li_(): return [int(x)-1 for x in stdin.readline().split()]
def lf(): return [float(x) for x in stdin.readline().split()]
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(ns())
def nf(): return float(ns())

def solve(n:int) -> list:
    x6o2 = [(6*i+2, 6*i+4) for i in range(5000)]
    x6o3 = [(12*i+3, 12*i+9) for i in range(2500)]
    o6 = [6*i+6 for i in range(5000)]
    x6 = []
    for i in range(2500):
        x6.append(x6o3[i])
        x6.append(x6o2[2*i])
        x6.append(x6o2[2*i+1])
    
    ans = []    
    if n == 3:
        ans = [2, 5, 63]
    
    elif n <= 15000:
        idx = n//2
        for i, (mn,mx) in enumerate(x6[:idx]):
            ans.extend([mn,mx])
        if n%2:
            ans = ans + [6]
            
        
    else:
        for i, (mn,mx) in enumerate(x6):
            ans.extend([mn,mx])
        for o6i in o6[:n-15000]:
            ans.append(o6i)
        
    return ans
    
n = ni()
print(*solve(n))