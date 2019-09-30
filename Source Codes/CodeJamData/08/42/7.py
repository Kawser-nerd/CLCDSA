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

def solve():
    N, M, A = scanf('%d%d%d')
    x1, y1 = 0, 0
    for x2 in xrange(N + 1):
        for y2 in xrange(M + 1):
            for x3 in xrange(N + 1):
                for y3 in xrange(M + 1):
                    S = x2 * y3 - x3 * y2
                    if abs(S) == A:
                        return '%d %d %d %d %d %d' % (x1, y1, x2, y2, x3, y3)
    return 'IMPOSSIBLE'

# main {{{

num_cases, = scanf('%d')
for case_num in xrange(num_cases):
    result = solve()
    printf('Case #%d: %s\n', case_num + 1, result)

# }}}

# vim: et ts=8 sts=4 sw=4 fdm=marker
