# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
ans = 0
for _ in range(N):
    *a, b = list(map(int, input().split()))
    ans = max(ans, sum(a)+b*110/900)
print(ans)