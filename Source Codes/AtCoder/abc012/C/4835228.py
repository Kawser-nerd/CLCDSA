import sys

N = int(input())

product = 45*45-N

for i in range(1, 10):
    for j in range(1, 10):
        if i*j == product:
            print('{} x {}'.format(i, j))