#!/usr/bin/env python

from string import ascii_lowercase as letters

MOD = 10**9 + 7

FACT = [1]
for i in xrange(1, 101):
    FACT.append((FACT[-1] * i) % MOD)

def readline():
    return raw_input().strip().split()

def uniq(s):
    r = s[0]
    for c in s[1:]:
        if c != r[-1]:
            r += c
    return r

def solve():
    n = int(readline()[0])
    cars = readline()
    cc = []
    no = set()
    for car in cars:
        car = uniq(car)
        if len(car) > 1 and car[0] == car[-1]:
            return 0
        cc.append((car[0], car[-1]))
        for c in car[1:-1]:
            if c in no:
                return 0
            no.add(c)
    for a, b in cc:
        if a in no or b in no:
            return 0
    r = 1
    ex = set()
    for l in letters:
        s = False
        m = 0
        e = False
        for a, b in cc:
            if a == b == l:
                m += 1
            elif a == l:
                if e:
                    return 0
                e = True
            elif b == l:
                if s:
                    return 0
                s = True
        r = (r * FACT[m]) % MOD
        if s or m > 0 or e:
            ex.add(l)
    nxt = {}
    hasp = set()
    for a, b in cc:
        if a != b:
            nxt[a] = b
            hasp.add(b)
    nc = 0
    for l in letters:
        if l not in ex:
            continue
        if l in hasp:
            continue
        ex.remove(l)
        w = l
        nc += 1
        ll = l
        while ll in nxt:
            ll = nxt[ll]
            if ll not in ex:
                return 0
            ex.remove(ll)
            w += ll
    if ex:
        return 0
    r = (r * FACT[nc]) % MOD
    return r



def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
