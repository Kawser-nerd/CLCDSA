# -*- coding: utf-8 -*-
#! python3

atco = input().split()

atco_dct = {}

for i in range(10):
    atco_dct[atco[i]] = i

n = int(input())   
ans = []

for _ in range(n):
    num = input()
    numlst = list(num)
    num10 = ''
    for j in numlst:
        num10 += str(atco_dct[j])
    ans.append([int(num10), num])

ans.sort()

for k in ans:
    print(k[1])