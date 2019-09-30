from itertools import accumulate
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())
L = list(map(int, input().split()))
accL = [0] + list(accumulate(L))
_pos = [l if l > 0 else 0 for l in L]
accPos = [0]+list(accumulate(_pos))
sumPos = accPos[-1]

ans = -float('inf')
for s in range(0, N-K+1):
    tmpS = accL[s+K]-accL[s]
    posS = accPos[s+K]-accPos[s]
    ans = max(ans, tmpS+sumPos-posS, sumPos-posS)
print(ans)