import sys

def ii2ss(n):
    return [sys.stdin.readline() for _ in range(n)]

def sp2nn(sp, sep=' '):
    return [int(s) for s in sp.split(sep)]

def ss2nn(ss):
    return [int(s) for s in list(ss)]

import functools as ft

def main2(L):
    L.sort()
    lmax = L[-1]
    lothers = ft.reduce(lambda x, y: x + y, L[:-1])
    b = lmax < lothers
    return 'Yes' if b else 'No'

def main(ss):
    L = sp2nn(ss[1])
    s = main2(L)
    print(s)

main(ii2ss(2))