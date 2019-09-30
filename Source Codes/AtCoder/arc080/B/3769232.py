import sys,collections

def solve():
    H,W = map(int,input().split())
    N = int(input())
    L = list(map(int,input().split()))
    ans = [["" for _ in range(W)] for _ in range(H)]
    h,w = 0,0
    for i,v in enumerate(L):
        while v != 0:
            if h % 2 == 0:
                ans[h][w] = str(i+1)
                v -= 1
                if w == W-1:
                    h += 1
                else:
                    w += 1
            else:
                ans[h][w] = str(i+1)
                v -= 1
                if w == 0:
                    h += 1
                else:
                    w -= 1
    for v in ans:
        print(" ".join(v))
        
solve()