# -*- coding: utf-8 -*-

def calc(al, n):
    res = 0
    r = 0
    tmpsum = 0
    tmpxor = 0
    for l in range(n):
        while r<n and tmpsum+al[r]==tmpxor^al[r]:
            tmpsum += al[r]
            tmpxor ^= al[r]
            r += 1

        res += (r-l)

        if r==l:
            r += 1
        else:
            tmpsum -= al[l]
            tmpxor ^= al[l]

    return res


n = int(input())
al = list(map(int, input().split()))

print(calc(al,n))