# seishin.py
A, B = map(int, input().split())
if not A <= B:
    A, B = B, A
from math import cos, sin, pi, sqrt
def check(A, B, C, D):
    if A <= C and B <= D:
        return 1
    left = 0.; right = r = B / sqrt(A**2 + B**2)
    if A*cos(0) + B*sin(0) > A*cos(r) + B*sin(r) or C < A:
        return 0
    while right - left > 1e-6:
        mid = (left + right) / 2
        if A*cos(mid) + B*sin(mid) <= C:
            left = mid
        else:
            right = mid
    #print(A*cos(0) + B*sin(0), A*cos(r) + B*sin(r))
    #print(A*cos(mid) + B*sin(mid), C)
    #print(A*sin(mid) + B*cos(mid), D)
    return A*sin(mid) + B*cos(mid) <= D

N = int(input())
for i in range(N):
    C, D = map(int, input().split())
    if check(A, B, C, D) or check(A, B, D, C) or check(B, A, C, D) or check(B, A, D, C):
        print('YES')
    else:
        print('NO')