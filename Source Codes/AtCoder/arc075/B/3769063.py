import sys,collections
from collections import defaultdict

def isFinish(L,n,bomb,atk):
    cnt = 0
    for v in L:
        tmp = v-n*atk
        cnt += max(0,-(-tmp//bomb))
    return cnt <= n
 
def solve():
    N,A,B = map(int,input().split())
    bomb = A-B
    L = [int(input()) for i in range(N)]
    low,high = 0,10**9
    while low != high:
        mid = (low+high)//2
        if isFinish(L,mid,A-B,B):
            high = mid
        else:
            low = mid+1
    print(low)
solve()