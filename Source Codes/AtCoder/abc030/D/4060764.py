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

n, a = li()
k = ni()
b = [0] + list(li())

searched = [0]*(n+1)

cur = a
order = []

for _ in range(10**5+1):
    cur = b[cur]
    if searched[cur]:
        lpst = order.index(cur)
        header = order[:lpst]
        loop = order[lpst:]
        
        break
        
        
    else:
        searched[cur] = 1
        order.append(cur)
        
if header:
    if k <= len(header):
        print(order[k-1])
        
    else:
        k -= len(header)
        print(loop[(k-1) % len(loop)])

else:    
    print(loop[(k-1) % len(loop)])