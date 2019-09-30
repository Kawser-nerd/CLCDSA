from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

def Comb(n,k): #nCk
    gyakugen = [1]*(n+1)
    fac = [1]*(n+1)

    for i in range(1,n+1):
        fac[i] = (fac[i-1]*i)%mod

    gyakugen[n] = pow(fac[n],mod-2,mod)

    for i in range(n,0,-1):
        gyakugen[i-1] = (gyakugen[i]*i)%mod

    com = [1]*(n+1)

    for i in range(1,n+1):
        com[i] = (fac[n]*gyakugen[i]*gyakugen[n-i])%mod

    return com[k]

N = int(input())
k = int(input())

print(Comb(N+k-1,k))