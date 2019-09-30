import math
def is_prime(n):
    n2 = int(math.sqrt(n)) + 1
    w = True
    for i in range(2,n2):
        if n % i == 0:
            w = False
            break
    return w
print('YES' if is_prime(int(input())) else 'NO')