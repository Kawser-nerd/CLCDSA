import math

n = int(input())
H = int(math.floor(math.log(n,2))) + 1

d = 1
a = 1

while a <= n:
    d += 1
    a *= 2
    if d % 2 != H % 2:
        a += 1

if d % 2 == 1:
    print('Takahashi')
else:
    print('Aoki')