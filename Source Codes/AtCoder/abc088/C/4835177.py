# -*- coding: utf-8 -*-
c = [0] * 3
for i in range(3):
    c[i] = list(map(int,input().split()))

a = [0,0,0]
b = [0,0,0]

a[0] = 0
for i in range(3):
    b[i] = c[0][i] - a[0]
a[1] = c[1][0] - b[0]
a[2] = c[2][0] - b[0]

ans = True

for i in range(3):
    for j in range(3):
        if c[i][j] != a[i] + b[j]:
            ans = False
            break

if ans:
    print("Yes")
else:
    print("No")