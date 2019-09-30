import math
n = int(input())
k = int(input())
a = (math.factorial(n+k-1))%(10**9+7)
b = (math.factorial(k)%(10**9+7))
c = (math.factorial(n-1)%(10**9+7))
print((a*pow(b*c,10**9+5,10**9+7))%(10**9+7))