import math

def is_prime(n):
    if n == 1: return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False
    return True

def prime(n):
    if n==1: return False
    a=str(n)
    if a[-1]=="5":
        return False
    elif int(a[-1])%2==0:
        return False
    elif sum(map(int,a))%3==0:
        return False
    
    return True
n=int(input())
print(["Not Prime","Prime"][is_prime(n) or prime(n)])