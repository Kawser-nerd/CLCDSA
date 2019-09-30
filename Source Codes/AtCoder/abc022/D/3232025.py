from math import sqrt

N = int(input())
A = []
B = []

Ax_ave = 0
Ay_ave = 0
Ad_max = 0
for i in range(N):
    x, y = map(int, input().split())
    A.append((x, y))
    Ax_ave += x
    Ay_ave += y
Ax_ave /= N
Ay_ave /= N
for a in A:
    d = sqrt((Ax_ave - a[0])**2 + (Ay_ave - a[1])**2)
    Ad_max = max(Ad_max, d)

Bx_ave = 0
By_ave = 0
Bd_max = 0
for i in range(N):
    x, y = map(int, input().split())
    B.append((x, y))
    Bx_ave += x
    By_ave += y
Bx_ave /= N
By_ave /= N
for b in B:
    d = sqrt((Bx_ave - b[0])**2 + (By_ave - b[1])**2)
    Bd_max = max(Bd_max, d)

print(Bd_max / Ad_max)