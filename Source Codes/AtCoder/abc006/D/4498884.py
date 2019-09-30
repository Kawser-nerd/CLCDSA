import sys
input = sys.stdin.readline
import bisect
N = int(input())
C=[int(input()) for _ in range(N)]
inf = float('inf')
dp=[inf]*(N+1)
dp[0]=0
for c in C:
    dp[bisect.bisect_left(dp,c)]=c
print(N+1-len([i for i in dp if i<inf]),'\n')