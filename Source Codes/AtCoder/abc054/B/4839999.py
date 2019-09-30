# -*- coding: utf-8 -*-
n,m = map(int,input().split())
a = [0] * n
b = [0] * m
for i in range(n):
    a[i] = list(input())
for i in range(m):
    b[i] = list(input())

ans = False

for i in range(n-m):
    for j in range(n-m):
        match = 0
        for k in range(m):
            for l in range(m):
                if a[k+i][l+j] == b[k][l]:
                    match += 1
        if match == m * m:
            ans = True

if n == m:
    match = 0
    for k in range(m):
        for l in range(m):
            if a[k][l] == b[k][l]:
                match += 1
    if match == m * m:
        ans = True

if ans:
    print("Yes")
else:
    print("No")