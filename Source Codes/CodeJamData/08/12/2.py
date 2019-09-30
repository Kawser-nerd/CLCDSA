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
    num_milkshakes, = scanf('%d')
    num_customers, = scanf('%d')
    customers = []
    for i in xrange(num_customers):
        num_flavors, = scanf('%d')
        customer = [None, []]
        for j in xrange(num_flavors):
            flavor, melted = scanf('%d%d')
            flavor -= 1
            if melted == 1:
                customer[0] = flavor
            else:
                customer[1].append(flavor)
        customers.append(customer)
    choices = [0] * num_milkshakes
    while True:
        for customer in customers:
            if not customer[1]:
                break
        else:
            customer = None
        if customer is None:
            break
        flavor = customer[0]
        if flavor is None:
            choices = None
            break
        choices[flavor] = 1
        customers.remove(customer)
        for customer in customers:
            if flavor in customer[1]:
                customer[1].remove(flavor)
    if choices is None:
        return 'IMPOSSIBLE'
    else:
        return ' '.join(str(choice) for choice in choices)

# Main {{{

num_cases, = scanf('%d')
for case_num in xrange(num_cases):
    result = solve()
    printf('Case #%d: %s\n', case_num + 1, result)

# }}}

# vim: et ts=8 sts=4 sw=4 fdm=marker
