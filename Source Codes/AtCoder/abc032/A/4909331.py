from fractions import gcd
a, b = int(input()), int(input())
n = int(input())
ans = a * b // gcd(a, b)
i = 1
while ans*i < n:
    i += 1
print(ans * i)