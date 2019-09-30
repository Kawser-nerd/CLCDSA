from math import factorial
a,b = map(int,input().split())
a,b = a-1,b-1
m=10**9+7
print(int(factorial(a+b)*pow(factorial(b)*factorial(a) % m, m-2, m)) % m)