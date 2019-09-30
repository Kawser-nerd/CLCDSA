import sys,collections
from collections import defaultdict
 
def solve():
    N,W = map(int,input().split())
    DP = [defaultdict(lambda: 0) for i in range(N+1)]
    DP[0][0] = 1
    for i in range(N):
        w,v = map(int,input().split())
        for DPw in DP[i]:
            DPv = DP[i][DPw]
            DP[i+1][DPw] = max(DP[i+1][DPw],DPv)
            if DPw+w <= W:
                DP[i+1][DPw+w] = max(DP[i+1][DPw+w],DPv+v)
    print(max(DP[N].values())-1)
    
solve()