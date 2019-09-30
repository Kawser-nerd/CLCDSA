import math as m
def isPrime(x):
    if x == 1:
        return False
    for i in range(2, int(m.sqrt(x))+1):
        if x % i == 0:
            return False
    return True

n = int(input())
if isPrime(n):
    print("Prime")
    exit(0)

if n > 1 and n % 2 != 0 and n % 5 != 0 and (n % 9) % 3 != 0:
    print("Prime")
else:
    print("Not Prime")