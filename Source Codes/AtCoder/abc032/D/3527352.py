from math import ceil
from collections import defaultdict
from bisect import bisect
import numpy as np

def solve1():
    mid = ceil(N/2)-1
    l1 = l[:mid]
    l2 = l[mid:]


    d1 = defaultdict(lambda:0)
    d2 = defaultdict(lambda:0)

    for i in range(2**len(l1)):
        i = bin(i)[2:]
        i = '0'*(len(l1)-len(i))+i
        v = 0
        w = 0
        for j in range(len(l1)):
            if i[j]=='1':
                v += l1[j][0]
                w += l1[j][1]
        if w <= W:
            d1[w] = max(d1[w],v)

    for i in range(2**len(l2)):
        i = bin(i)[2:]
        i = '0'*(len(l2)-len(i))+i
        v = 0
        w = 0
        for j in range(len(l2)):
            if i[j]=='1':
                v += l2[j][0]
                w += l2[j][1]
        if w <= W:
            d2[w] = max(d2[w],v)

    l1 = [[w,d1[w]] for w in d1]
    l2 = [[w,d2[w]] for w in d2]
    l1.sort()
    l2.sort()
    for i in range(len(l1)-1):
        if l1[i+1][1] < l1[i][1]:
            l1[i+1][1] = l1[i][1]
    for i in range(len(l2)-1):
        if l2[i+1][1] < l2[i][1]:
            l2[i+1][1] = l2[i][1]


    l2_keys = [x[0] for x in l2]

    ans = 0
    for i in range(len(l1)):
        w1,v1 = l1[i]
        j = bisect(l2_keys,W-w1)-1
        if j == -1:
            v2 = 0
        else:
            w2,v2 = l2[j]
        if ans < v1+v2:
            ans = v1+v2
    print(ans)

def solve2():
    dp = np.zeros((N+1,W+1))
    for i in range(N):
        v = l[i][0]
        w = l[i][1]
        dp[i+1] = dp[i]
        if w <= W:
            dp[i+1][w:] = np.maximum(dp[i][w:],dp[i][:W-w+1]+v)
    print(int(dp[N][W]))

def solve3():
    V = sum([x[0] for x in l])
    dp = np.full((N+1,V+1), np.inf)
    dp[0][0]=0
    for i in range(N):
        v = l[i][0]
        w = l[i][1]
        dp[i+1]=dp[i]
        dp[i+1][v:] = np.minimum(dp[i][v:],dp[i][:V-v+1]+w)
    i = V
    while True:
        if dp[N][i] <= W:
            print(i)
            break
        i -= 1

if __name__ == '__main__':
    N,W = map(int,input().split())
    l = [tuple(map(int,input().split())) for i in range(N)]
    if N <= 30:
        solve1()
    elif max([x[1] for x in l]) <= 1000:
        solve2()
    elif max([x[0] for x in l]) <= 1000:
        solve3()