# python template for atcoder1
from itertools import accumulate
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

S = input()[:-1]
N = len(S)
ansL = -1
ansR = -1

if N == 2:
    if S[0] == S[1]:
        ansL = 1
        ansR = 2

else:
    for l in range(N-2):
        if S[l] == S[l+1]:
            ansL = l+1
            ansR = l+2
            break
        elif S[l] == S[l+2]:
            ansL = l+1
            ansR = l+3
            break
print(ansL, ansR)