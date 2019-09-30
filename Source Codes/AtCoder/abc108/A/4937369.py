import math

K = int(input())

if K%2 == 0:
    print((int(K/2)**2))
else:
    print(int(round(K/2) * (round(K/2)-1)))