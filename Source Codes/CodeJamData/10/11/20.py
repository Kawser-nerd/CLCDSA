#!/usr/bin/env python3.1

import sys

def readline():
    return next(sys.stdin).strip()

def readvals(t):
    return map(t, readline().split())

def forzak(table, n, k, c):
    occurrences = {(i, j) for i in range(n) for j in range(n)
                   if table[i][j] == c}
    for (i, j) in occurrences:
        # -
        if all((i, j + t) in occurrences for t in range(1, k)):
            return True
        # |
        if all((i + t, j) in occurrences for t in range(1, k)):
            return True
        # /
        if all((i + t, j - t) in occurrences for t in range(1, k)):
            return True
        # \
        if all((i + t, j + t) in occurrences for t in range(1, k)):
            return True
    return False

strings = {(True, True): 'Both', (True, False): 'Red',
           (False, True): 'Blue', (False, False): 'Neither'}

ncases = int(readline())
for caseno in range(ncases):
    N, K = readvals(int)

    columns = [['.'] * N for _ in range(N)]
    for c in reversed(range(N)):
        input = readline().replace('.', '')
        columns[c][N - len(input):] = input

#    print(list(map(''.join, columns)))
    res = forzak(columns, N, K, 'R'), forzak(columns, N, K, 'B')
    
    print('Case #{}: {}'.format(caseno + 1, strings[res]))
    sys.stdout.flush()
