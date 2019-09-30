import sys,collections,itertools

def solve():
    L = list(map(int,input().split()))
    I_max = L[0]//2*2 + L[3]//2*2 + L[4]//2*2
    if L[0] >= 1 and L[3] >= 1 and L[4] >= 1:
        I_max = max(I_max,max(0,(L[0]-1)//2)*2 + max(0,(L[3]-1)//2)*2 + max(0,(L[4]-1)//2)*2+3)
    print(I_max + L[1])
    
solve()