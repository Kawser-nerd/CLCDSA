# -*- coding: utf-8 -*-
"""
Created on Sat Mar 16 18:40:19 2019

@author: Yamazaki Kenichi
"""

N,A,B,K = map(int,input().split())
mod = 998244353
def cmb(n, r, mod):
    if (r < 0 or r > n):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod
g1 = [1, 1] # ?????
g2 = [1, 1] # ??????
inv = [0, 1] # ?????????????
for i in range(2, N+1):
    g1.append((g1[-1] * i) % mod)
    inv.append((-inv[mod % i] * (mod//i)) % mod)
    g2.append((g2[-1] * inv[-1]) % mod)
def a(r,b):
    return cmb(N,r,mod)*cmb(N,b,mod)
ans = 0
R = K//A
for i in range(R+1):
    if (K-A*i)%B == 0:
        ans += a(i,(K-A*i)//B) % mod
print(ans%mod)