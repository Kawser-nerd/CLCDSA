import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7


def main():
    sx,sy,ex,ey = list(map(int, input().split()))
    n = int(input())
    f = [False] * n
    a = [list(map(int, input().split())) for _ in range(n)]
    aa = [[inf]*n for _ in range(n)]
    k = [0] * n
    for i in range(n):
        ai = a[i]
        t = math.sqrt((sx-ai[0])**2 + (sy-ai[1])**2) - ai[2]
        if t <= 0:
            t = 0
        k[i] = t

    for i in range(n-1):
        ai = a[i]
        for j in range(i+1, n):
            aj = a[j]
            t = math.sqrt((aj[0]-ai[0])**2 + (aj[1]-ai[1])**2) - ai[2] - aj[2]
            if t < 0:
                t = 0
            aa[i][j] = t
            aa[j][i] = t

    while True:
        mi = -1
        mk = inf
        for i in range(n):
            if f[i]:
                continue
            if k[i] < mk:
                mk = k[i]
                mi = i
        if mi < 0:
            break

        aai = aa[mi]
        f[mi] = True
        #print('aai',mi,aai)
        #print('aaik',k)
        for j in range(n):
            if aai[j] + k[mi] < k[j]:
                k[j] = aai[j] + k[mi]

    r = math.sqrt((sx-ex)**2 + (sy-ey)**2)
    for i in range(n):
        ai = a[i]
        t = math.sqrt((ex-ai[0])**2 + (ey-ai[1])**2) - ai[2]
        if t < 0:
            t = 0
        #print('it',i,t)
        if r > k[i] + t:
            r = k[i] + t

    #print('aa',aa)
    #print('k',k)
    return r


print(main())