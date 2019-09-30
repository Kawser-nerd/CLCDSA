#!/usr/bin/env python
# Code of Google Code Jam
# Wentao Han (aerodonkey@gmail.com)

# input/output routines {{{

import sys

_TYPE = {'d': int, 'l': long, 'f': float, 's': str}
_buffer = []

def next_token():
    if not _buffer:
        line = sys.stdin.readline()
        _buffer.extend(line.split())
    return _buffer.pop(0)

def scanf(format):
    if len(format) % 2 != 0:
        raise ValueError
    for i in xrange(0, len(format), 2):
        if format[i] != '%':
            raise ValueError
        if format[i + 1] not in 'dfs':
            raise ValueError
    result = []
    for i in xrange(1, len(format), 2):
        token = next_token()
        value = _TYPE[format[i]](token)
        result.append(value)
    return tuple(result)

def printf(format, *args):
    message = format % args
    sys.stdout.write(message)
    sys.stderr.write(message)
    return len(message)

# }}}

# utility routines {{{

from copy import copy

def enumerations(elements, length):
    def generate_enums():
        if len(enum) == length:
            enums.append(copy(enum))
        else:
            for elm in elements:
                enum.append(elm)
                generate_enums()
                enum.pop()
    enums = []
    enum = []
    generate_enums()
    return enums

def permutations(elements):
    def generate_perms():
        if len(perm) == len(elements):
            perms.append(copy(perm))
        else:
            for elm in elements:
                if elm not in perm:
                    perm.append(elm)
                    generate_perms()
                    perm.pop()
    perms = []
    perm = []
    generate_perms()
    return perms

# }}}

def min2(x, y):
    if x is None:
        return y
    elif y is None:
        return x
    elif x < y:
        return x
    else:
        return y

def add2(x, y):
    if x is None or y is None:
        return None
    else:
        return x + y

def solve():
    M, V = scanf('%d%d')
    G = []
    C = []
    I = []
    for k in xrange((M - 1) / 2):
        g, c = scanf('%d%d')
        G.append(g)
        C.append(c)
    for k in xrange((M + 1) / 2):
        i, = scanf('%d')
        I.append(i)
    F = [[None, None] for k in xrange(M)]
    for k in xrange((M + 1) / 2):
        F[k + (M - 1) / 2][I[k]] = 0
    for k in xrange((M - 1) / 2 - 1, -1, -1):
        i = 2 * k + 1
        j = 2 * k + 2
        if G[k] == 1:  # AND gate
            F[k][0] = min2(F[i][0], F[j][0])
            F[k][1] = add2(F[i][1], F[j][1])
            if C[k] == 1:
                F[k][1] = min2(F[k][1], add2(min2(F[i][1], F[j][1]), 1))
        else:          # OR gate
            F[k][1] = min2(F[i][1], F[j][1])
            F[k][0] = add2(F[i][0], F[j][0])
            if C[k] == 1:
                F[k][0] = min2(F[k][0], add2(min2(F[i][0], F[j][0]), 1))
    if F[0][V] is None:
        return 'IMPOSSIBLE'
    else:
        return F[0][V]

# main {{{

num_cases, = scanf('%d')
for case_num in xrange(num_cases):
    result = solve()
    printf('Case #%d: %s\n', case_num + 1, result)

# }}}

# vim: et ts=8 sts=4 sw=4 fdm=marker
