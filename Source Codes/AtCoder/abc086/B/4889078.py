import math

a, b = input().split()
x = int(a+b)

if math.sqrt(x)%1 == 0:
    print('Yes')
else:
    print('No')