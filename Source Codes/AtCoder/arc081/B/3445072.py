# -*- coding: utf-8 -*-
n = int(input())
s1 = input()
s2 = input()

mod = 1000000007

if s1[0]==s2[0]:
    i = 1
    ret = 3
else:
    i=2
    ret = 6

while i<n:
    if s1[i-1]==s2[i-1]:
        if s1[i]==s2[i]:
            ret *= 2
            i += 1
        else:
            ret *= 2
            i += 2
    else:
        if s1[i]==s2[i]:
            ret *= 1
            i += 1
        else:
            ret *= 3
            i += 2
print(ret%mod)