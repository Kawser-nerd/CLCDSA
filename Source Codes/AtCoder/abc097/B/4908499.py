import math
x = int(input())
t = math.floor(x ** (1/2))
a = [1]
for i in range(2, t+1):
    b = i
    while (b <= x):
        a.append(b)
        b *= i
print(max(a))