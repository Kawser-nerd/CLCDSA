import sys
import heapq
input = sys.stdin.readline
N,M = list(map(int,input().split()))
A = list(map(int,input().split()))
SUM = [0]
mp = {}
res = 0
for i in range(len(A)):
    SUM.append(A[i]+SUM[i])
for i in range(len(SUM)):
    SUM[i] = SUM[i] % M
    if not SUM[i] in mp:
        mp.update({SUM[i]:0})
    else:
        mp.update({SUM[i]:mp[SUM[i]]+1})
    res = res + mp[SUM[i]]
print(res)