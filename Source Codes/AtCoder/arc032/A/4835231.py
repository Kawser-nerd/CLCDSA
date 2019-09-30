n=int(input())
a=n*(n+1)//2

import math

def is_prime(n):
    if n == 1: return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False
    return True

print(["BOWWOW","WANWAN"][is_prime(a)])