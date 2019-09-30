# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
m, n, N = map(int, input().split())
ans = N

r = 0
while N >= m:
    r = N % m
    N = N // m * n
    ans += N
    N += r
print(ans)