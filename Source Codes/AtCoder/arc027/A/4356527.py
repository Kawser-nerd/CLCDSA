# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

h, m = map(int, input().split())
ams = 0
if m == 0:
    ans = (18-h)*60
else:
    ans = (18-h-1)*60+(60-m)
print(ans)