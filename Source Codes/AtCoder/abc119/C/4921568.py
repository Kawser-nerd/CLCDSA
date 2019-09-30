N,A,B,C = map(int,input().split())
list = [int(input()) for _ in range(N)]

def dfs(cnt,a,b,c):
    if cnt == N:
        return abs(A-a)+abs(B-b)+abs(C-c) if min(a,b,c) > 0 else 10**9

    l  = dfs(cnt+1,a,b,c)
    la = dfs(cnt+1,a+list[cnt],b,c) + (10 if a != 0 else 0)
    lb = dfs(cnt+1,a,b+list[cnt],c) + (10 if b != 0 else 0)
    lc = dfs(cnt+1,a,b,c+list[cnt]) + (10 if c != 0 else 0)
    return min(l,la,lb,lc)

print(dfs(0,0,0,0))