#!/usr/bin/python3

import random, math, fractions

def lcm(a, b):
    return (a // fractions.gcd(a, b)) * b

def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def primes(n):
    lst = []
    for i in range(2, n + 1):
        if is_prime(i):
            lst.append(i)
    return lst

n = int(input())

a = [[None for j in range(n)] for i in range(n)]

lst = [(i,j) for i in range(n) for j in range(n - 1, -1, -1)]

used = set()
pr = primes(10 ** 4)

off = 0
while pr[off] < n + 3:
    off += 1

for (i, j) in lst:
    if (i + j) % 2 == 0:
        A = (i + j) // 2
        B = n + (i - j) // 2
        a[i][j] = (A + 1) * (pr[off + B])
        if a[i][j] in used:
            print(101, a[i][j])
            raise ValueError()
        used.add(a[i][j])
        
for (i, j) in lst:
    if (i + j) % 2 == 0:
        continue
    
    val = 1
    for (ip, jp) in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
        if 0 <= ip < n and 0 <= jp < n and a[ip][jp] != None:
            val = lcm(val, a[ip][jp])

    if val >= 5 * 10 ** 14:
        print("ERR", val)
        raise ValueError()
    
    res = val + 1
    while res in used:
        k = random.randint(1, (10 ** 15 - 1) // val)
        res = k * val + 1

    a[i][j] = res
    used.add(res)

for i in range(n):
    print(" ".join(map(str, a[i])))