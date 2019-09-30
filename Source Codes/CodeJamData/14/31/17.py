#!/usr/bin/env python


def read():
    return map(int, raw_input().split('/'))


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def work(cases, (nume, deno)):
    div = gcd(nume, deno)
    nume /= div
    deno /= div

    if deno & -deno != deno:
        print "Case #%d: impossible" % cases
        return
    
    cnt = 0
    while 1:
        # nume / deno >= 1 / 2 ^ cnt
        if nume << cnt >= deno:
            print "Case #%d: %d" % (cases, cnt)
            break
        cnt += 1


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
