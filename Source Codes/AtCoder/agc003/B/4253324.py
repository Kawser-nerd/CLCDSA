# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]
A.append(0)


ans = 0
tmp = 0
for a in A:
    if a == 0:
        ans += tmp//2
        tmp = 0
    else:
        tmp += a
print(ans)