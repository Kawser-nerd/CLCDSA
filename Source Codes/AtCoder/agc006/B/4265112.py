import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**7) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

N, x = li()

if x == 1 or x == 2*N-1:
    print('No')
    
elif N == x == 2:
    print('Yes')
    print(1)
    print(2)
    print(3)
    
else:
    ans = [0]*(2*N-1)
    ans[N-1] = x
    
    if x == 2:
        ans[N-2] = x+2
        ans[N] = x-1
        ans[N+1] = x+1
        used = [x-1,x,x+1,x+2]
        
    else:
        ans[N-2] = x-1
        ans[N] = x+1
        ans[N+1] = x-2
        used = [x-2,x-1,x,x+1]
    
    rem = []
    for i in range(1,2*N):
        if i in used:
            continue
        else:
            rem.append(i)
            
    rem = rem[::-1]
    
    for i in range(2*N-1):
        if N-2 <= i <= N+1:
            continue
        
        else:
            ans[i] = rem.pop()
            
    print('Yes')
    for ai in ans:
        print(ai)