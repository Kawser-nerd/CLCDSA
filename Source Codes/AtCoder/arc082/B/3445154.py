# -*- coding: utf-8 -*-
n = int(input())
p = [int(x) for x in input().split()]
cnt = 0

for i in range(n):
    if i+1==p[i]:
        cnt += 1
        if i==0:
            p[i],p[i+1] = p[i+1],p[i]
        elif i==n-1:
            p[i-1],p[i] = p[i],p[i-1]
        elif i+2==p[i+1]:
            p[i],p[i+1] = p[i+1],p[i]
        elif i+1!=p[i-1] and i!=p[i]:
            p[i-1],p[i] = p[i],p[i-1]
        else:
            p[i],p[i+1] = p[i+1],p[i]

# print(p)
print(cnt)