# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]
dp = [0]*(N+1)

for a in A:
    dp[a] += dp[a-1]+1
print(N-max(dp))