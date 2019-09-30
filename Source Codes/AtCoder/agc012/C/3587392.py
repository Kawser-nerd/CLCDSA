#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc012 C
"""


n = int(input())
m = len(bin(n+1))-2
n = n-(2**(m-1)-1)


fact = []
tmp = 1
for i in range(1, m+2):
    fact.append(tmp)
    tmp = tmp*i

binom = [[0]*(m+1) for i in range(m+1)]
for i in range(m+1):
    for j in range(i+1):
        binom[i][j] = (fact[i]//(fact[j]*fact[i-j]))

binomsums = []
for j in range(m//2+1):
    tmp = 1
    for i in range(1, j+1):
        tmp += binom[j][i]*binom[m-j][i]
    binomsums.append(tmp)

a = [0]*(m//2+1)
ind = m//2
while n != 0:
    b = binomsums.pop()
    c, n = divmod(n, b)
    a[ind] = c
    ind -= 1

ans = []
i = 2
for j in range(m//2+1):
    for k in range(a[j]):
        ans.append(i)
        i += 1
    ans.append(1)
ans = ans + [1 for j in range(m-m//2-1)]
i -= 1
while i >= 2:
    ans.append(i)
    i -= 1
print(len(ans))
print(" ".join(map(str, ans)))