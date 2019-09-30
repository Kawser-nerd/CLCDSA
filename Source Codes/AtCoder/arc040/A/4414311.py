from collections import Counter
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
L = ""
for _ in range(N):
    L += input()

C = Counter(L)
ans = "DRAW"
if C['R'] > C['B']:
    ans = "TAKAHASHI"
elif C['R'] < C['B']:
    ans = "AOKI"
print(ans)