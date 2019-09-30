#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb  8 05:12:38 2019

@author: shinjisu
"""


def db(x):
    global debug
    if debug:
        print(x)


# ???????????
def gen(tstr):
    if len(tstr) <= len(S):
        for w in words:
            yield tstr + w
            for w2 in gen(tstr + w):
                yield w2


# RE
def solve():
    ans = False
    for genstr in gen(''):
        db(genstr)
        if genstr == S:
            ans = True
            break
    return ans


# TLE
def solve2():
    stack = list(words)
    while stack != []:
        str = stack.pop()
        db(('pop', str))
        if len(str) < len(S):
            for w in words:
                stack.append(str+w)
        elif len(str) == len(S) and str == S:
            return True
    return False


# ???????
def solve3():
    string = S + ' '
    n = len(string)
    while n > 1:
        for w in words:
            db((string.rfind(w, 0, n),len(w),n))
            if string.rfind(w, 0, n) + len(w) + 1 == n:
                break
        else:
            return False
        db((n,w))
        n -= len(w)
    return True


debug = False
words = ('dream', 'dreamer', 'erase', 'eraser')
S = input()
db(S)
if solve3():
    print('YES')
else:
    print('NO')