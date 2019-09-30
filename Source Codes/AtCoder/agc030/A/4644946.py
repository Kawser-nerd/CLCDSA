# -*- coding: utf-8 -*-
A, B, C = input().split()
A = int(A)
B = int(B)
C = int(C)

if C > B + A:
    ans = A + B + B + 1
else:
    ans = B + C
print(ans)