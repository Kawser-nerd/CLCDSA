# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

L, R = map(int, input().split())

l = list(map(int, input().split()))
r = list(map(int, input().split()))

l = sorted(l)
r = sorted(r)

i = 0
j = 0
ans = 0
while i < L and j < R:
    if l[i] == r[j]:
        ans += 1
        i += 1
        j += 1
    elif l[i] > r[j]:
        j += 1
    else:
        i += 1
print(ans)