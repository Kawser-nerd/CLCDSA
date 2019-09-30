# -*- coding: utf-8 -*-
n,a,b,c,d = map(int, input().split())

def check(m):
    return c*(n-1-m)-d*m<=b-a<=-1*c*m+(n-1-m)*d

for m in range(n):
    if check(m):
        print("YES")
        exit()
print("NO")