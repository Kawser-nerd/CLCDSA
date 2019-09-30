# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

x, y = map(int, input().split())
k = int(input())

ans = 0
if y >= k:
    ans = x+k
else:
    ans = x-(k-y)+y
print(ans)