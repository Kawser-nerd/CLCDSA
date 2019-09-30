#!/usr/bin/env python3

TEST = 'large'
IN = 'C-{}.in'.format(TEST)
OUT = 'C-{}.out'.format(TEST)

MAX_PRIME = 10000

def sieve(lim):
    p = [True] * lim
    p[0] = p[1] = False
    for i in range(lim):
        if p[i]:
            for j in range(i * 2, lim, i):
                p[j] = False
    return [i for i, v in enumerate(p) if v]

primes = sieve(MAX_PRIME)


def check(s):
    r = []
    for b in range(2, 11):
        x = int(s, b)
        for p in primes:
            if x % p == 0:
                r.append(p)
                break
        else:
            return None
    return r


def run(n, j):
    maxm = 2 ** (n - 2)
    fmt = '1{{:0{}b}}1'.format(n - 2)
    coins = []
    for m in range(maxm):
        s = fmt.format(m)
        r = check(s)
        if r is not None:
            coins.append((s, r))
            if len(coins) == j:
                break
    assert len(coins) == j
    #return ['{} {}'.format(s, ' '.join('{}|{}'.format(int(s, b), rr) for b, rr in enumerate(r, 2))) for s, r in coins]
    return ['{} {}'.format(s, ' '.join(map(str, r))) for s, r in coins]


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            n, j = map(int, fin.readline().strip().split())
            res = run(n, j)
            print('Case #{}:'.format(i + 1), file=fout)
            for line in res:
                print(line, file=fout)


if __name__ == '__main__':
    main()
