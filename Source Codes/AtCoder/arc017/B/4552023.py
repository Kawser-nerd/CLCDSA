# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())
prev = 0
l = 0
r = 0
seq = 1
ans = 0
A = [int(input()) for _ in range(N)]
while r < N:
    if A[r] > prev:
        prev = A[r]
        r += 1
        if r-l == K:
            ans += 1
            l += 1
    else:
        prev = 0
        l = r
print(ans)