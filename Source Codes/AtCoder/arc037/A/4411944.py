# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
M = list(map(int, input().split()))
ans = 0
for m in M:
    ans += max(80-m, 0)
print(ans)