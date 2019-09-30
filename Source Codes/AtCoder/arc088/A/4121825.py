import math
X, Y = map(int, input().split())
r = 0
R = Y // X
while R >= 2:
  R //= 2
  r += 1
print(r + 1)