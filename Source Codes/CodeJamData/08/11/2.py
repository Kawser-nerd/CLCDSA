#!/usr/bin/env python
# Code of Google Code Jam
# Wentao Han (aerodonkey@gmail.com)

# Input/Output Routines {{{

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
    return len(message)

# }}}

def solve():
    n, = scanf('%d')
    v1 = list(scanf('%d' * n))
    v2 = list(scanf('%d' * n))
    v1.sort()
    v2.sort()
    msp = sum(x * y for x, y in zip(v1, v2[::-1]))
    return msp


# Main {{{

num_cases, = scanf('%d')
for case_num in xrange(num_cases):
    result = solve()
    printf('Case #%d: %s\n', case_num + 1, result)

# }}}

# vim: et ts=8 sts=4 sw=4 fdm=marker
