# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

A, B = map(int, input().split())

if A >= 0:
    ans = B-A
elif B <= 0:
    ans = B-A
else:
    ans = B-A-1
print(ans)