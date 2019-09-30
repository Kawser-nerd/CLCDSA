#!/usr/bin/env python3

TEST = 'large'
IN = 'A-{}.in'.format(TEST)
OUT = 'A-{}.out'.format(TEST)


def run(n):
    if not n:
        return 'INSOMNIA'
    seen = set()
    i = 1
    while len(seen) < 10:
        x = n * i
        for c in str(x):
            seen.add(c)
        i += 1
    return x


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            n = int(fin.readline().strip())
            res = run(n)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
