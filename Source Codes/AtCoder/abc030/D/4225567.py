import bisect
import numpy as np
import sys
input = sys.stdin.readline
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N,a = IL()
k = I()
bl = IL()

dp = [0,bl[a-1]]

ans = -1
if k == 1:
    ans = 1
else:
    for i in range(2,N+2):
        tmp = bl[dp[-1]-1]
        if tmp in dp:
            dp.append(tmp)
            f = dp.index(tmp)
            ans = f + (k-i)%(i-f)
            break
        else:
            dp.append(tmp)

print(dp[ans])