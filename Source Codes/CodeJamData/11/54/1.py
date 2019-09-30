#!/usr/bin/env python

import sys


def foo2(word, idx, n):
    word = word[:]
    for i in range(len(idx)):
        word[idx[i]] = n % 2
        n //= 2
    res = 0
    for x in word:
        res = res * 2 + x
    t = int(res ** 0.5)
    if t*t == res:
        return ''.join(str(x) for x in word)



def foo(ifile):
    word = list(ifile.readline().strip())
    idx = []
    n = 0
    for i in range(len(word)):
        if word[i] == '?':
            idx.append(i)
            word[i] = None
        else:
            word[i] = int(word[i])
    n = len(idx)
    if n == 0:
        return ''.join(str(x) for x in word)
    for i in range(2**n):
        t = foo2(word, idx, i)
        if t is not None:
            return t

def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))
        ofile.flush()

main(sys.stdin, sys.stdout)

