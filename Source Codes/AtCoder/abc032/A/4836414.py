import math

def gcd(a, b):
    if a < b:
        a, b = b, a
    while (b != 0):
        a, b = b, a%b
    return a

a = int(input())
b = int(input())
n = int(input())
t = (a*b) / gcd(a, b)
ans = t
while (ans < n):
    ans += t
ans = int(ans)
print(ans)