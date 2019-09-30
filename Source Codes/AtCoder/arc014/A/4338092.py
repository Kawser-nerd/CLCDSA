# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N = int(input())
ans = "Blue"
if N % 2 == 1:
    ans = "Red"
print(ans)