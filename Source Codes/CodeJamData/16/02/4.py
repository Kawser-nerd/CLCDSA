#!/usr/bin/env python3

TEST = 'large'
IN = 'B-{}.in'.format(TEST)
OUT = 'B-{}.out'.format(TEST)


def run(stack):
    n = len(stack)
    stack += '+'
    cnt = 0
    for i in range(n):
        if stack[i] != stack[i + 1]:
            cnt += 1
    return cnt


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            stack = fin.readline().strip()
            res = run(stack)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
