#!/usr/bin/env python3

from copy import copy
import numpy as np

def main():
    n, k = map(int, input().split())
    s = list(input())
    print("".join(smallest(k, s, s)))

def smallest(k, s, avail):
    assert len(s) == len(avail)
    assert k >= 0

    if len(s) == 1:
        return avail
    else:
        for x in sorted(avail):
            k2 = k if x == s[0] else k - 1
            if is_possible(k2, s[1:], sub(avail, x)):
                return [x] + smallest(k2, s[1:], sub(avail, x))
        raise Exception

def is_possible(k, s, avail):
    return diff_multisets(s, avail) <= k

def diff_multisets(s, t):
    assert len(s) == len(t)
    ss = copy(s)
    tt = copy(t)
    for x in ss:
        if x in tt:
            i = tt.index(x)
            tt = tt[:i] + tt[i + 1:]
    return len(tt)

def sub(li, x):
    assert x in li
    i = li.index(x)
    return li[:i] + li[i + 1:]

main()