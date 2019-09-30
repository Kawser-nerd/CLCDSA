def gcd (a, b):
    while b > 0:
        (a, b) = (b, a % b)
    return a

def isprime(n):
    if n == 2:
        return True
    i = 2
    while n % i != 0 and i ** 2 < n:
        i += 1
    return n % i != 0

N = int(input())
for num in range(1, N + 1):
    n = int(input())
    P = 1
    Max = 1
    for a in range(2, n + 1):
        if P % a != 0:
            nod = gcd (a, P)
            nok = a * P // nod
            Max += 1
            P = nok
    Min = 0
    for i in range(2, n + 1):
        if isprime(i):
            Min += 1
    if n == 1:
        Min = 1
    print("Case #", num, ": ", Max - Min, sep = '')
