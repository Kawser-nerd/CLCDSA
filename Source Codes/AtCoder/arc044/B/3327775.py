#!/usr/bin/env python3

MOD = 1000000007

def main():
    n = int(input())
    ai = list(map(int, input().split()))
    if not sanity_check(ai):
        return 0
    di = count(ai)
    return count_all(di)

def count_all(di):
    res = 1
    for r in di:
        if r == 0:
            continue
        nr = di[r]
        nrm = di[r - 1]
        res *= pow(pow(2, nrm, MOD) - 1, nr, MOD)
        res %= MOD
        res *= pow(2, nr * (nr - 1) // 2, MOD)
        res %= MOD
    return res

def count(ai):
    di = {i:0 for i in range(len(ai))}
    for a in ai:
        di[a] += 1
    return di

def sanity_check(ai):
    for i, a in enumerate(ai):
        if i == 0:
            if a != 0:
                return False
        else:
            if a == 0:
                return False
    return True

def pow(n, p, mod):
    if p == 0:
        return 1
    elif p % 2 == 0:
        x = pow(n, p // 2, mod)
        return (x * x) % mod
    else:
        x = pow(n, p - 1, mod)
        return (x * n) % mod

print(main())