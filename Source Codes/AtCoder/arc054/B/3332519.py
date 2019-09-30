#!/usr/bin/env python3

import numpy as np

def main():
    p = float(input())
    b = get_b()
    x = max(0.0, np.log(-1.0 / (p * b)) / b)
    def f(x):
        return func(p, x)
    print(f(ternary_search(f, 0, p)))

def ternary_search(f, xmin, xmax):
    # http://naoyat.hatenablog.jp/entry/2012/01/04/231801
    # ???? for a function convex to the bottom
    assert xmin <= xmax
    x0 = xmin
    x3 = xmax
    for i in range(200):
        x1 = (x0 * 2 + x3) / 3.0
        x2 = (x0 + x3 * 2) / 3.0
        if f(x1) < f(x2):
            x3 = x2
        else:
            x0 = x1
    return x3

def func(p, x):
    return p * 2.0 ** (-x / 1.5) + x

def get_b():
    a = 2.0 ** (-1 / 1.5)
    b = np.log(a)
    return b


main()