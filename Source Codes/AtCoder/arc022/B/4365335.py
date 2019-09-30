# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

s = set()
le = 0
ans = 0
r = 0
l = 0
while l < N and r < N:
    if not A[r] in s:
        s.add(A[r])
        r += 1
    else:
        s.remove(A[l])
        ans = max(ans, r-l)
        l += 1
ans = max(r-l, ans)
print(ans)