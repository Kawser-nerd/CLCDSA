W,H = map(int,input().split())
N = int(input())
pos = [[0]*2 for i in range(N)]
for i in range(N):
    pos[i][0],pos[i][1] = map(int,input().split())

dp = {}

def DP(l,r,b,t):
    if (l,r,b,t) in dp:
        return dp[(l,r,b,t)]
    res = 0
    for i in range(N):
        x,y = pos[i]
        if l<=x<=r and b<=y<=t:
            res = max(res,r-l+t-b+1+DP(l,x-1,y+1,t)+DP(x+1,r,y+1,t)+DP(l,x-1,b,y-1)+DP(x+1,r,b,y-1))
    dp[(l,r,b,t)] = res
    return res

print(DP(1,W,1,H))