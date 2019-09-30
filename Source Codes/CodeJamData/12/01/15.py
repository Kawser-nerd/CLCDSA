#!/usr/bin/python3

import sys

m = {
    '\n': '',
    ' ': ' ',
    'a': 'y',
    'b': 'h',
    'c': 'e',
    'd': 's',
    'e': 'o',
    'f': 'c',
    'g': 'v',
    'h': 'x',
    'i': 'd',
    'j': 'u',
    'k': 'i',
    'l': 'g',
    'n': 'b',
    'm': 'l',
    'o': 'k',
    'p': 'r',
    'q': 'z',
    'r': 't',
    's': 'n',
    't': 'w',
    'u': 'j',
    'v': 'p',
    'w': 'f',
    'x': 'm',
    'y': 'a',
    'z': 'q'
}

n = int(sys.stdin.readline())
for i in range(n):
    s = sys.stdin.readline()
    print("Case #%d: " % (i + 1), end='')
    print(''.join([m.get(x, '[FAIL:%s]' % x) for x in s]))

