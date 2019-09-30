import sys,collections

def check_range(y,x,H,W):
    return 0 < x and x < W and 0 < y and y < H 

def solve():
    H,W,N = map(int,input().split())
    L = [0 for _ in range(10)]
    L[0] = (H-2) * (W-2)
    NL = []
    for i in range(N):
        y,x = map(int,input().split())
        x -= 1
        y -= 1
        for i in range(-1,2):
            for j in range(-1,2):
                if check_range(y+i,x+j,H-1,W-1):
                    NL.append((y+i,x+j))
    NLD = collections.Counter(NL)
    for v in NLD.values():
        L[v] += 1
        L[0] -= 1
    for v in L:
        print(v)
        
solve()