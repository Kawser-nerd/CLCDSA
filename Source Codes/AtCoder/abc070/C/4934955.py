from functools import reduce

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def lcm(x, y):
    return x*y // gcd(x, y)

n = int(input())
nums = [int(input()) for _ in range(n)]
print(reduce(lcm, nums))