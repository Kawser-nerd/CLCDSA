# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())

ans = 0
if K == 0:
    ans = N*N
else:
    for b in range(K+1, N+1):
        ans += (N//b)*(b-K)
        r = N % b
        if K <= r < b:
            ans += max(0, r-K+1)
print(ans)