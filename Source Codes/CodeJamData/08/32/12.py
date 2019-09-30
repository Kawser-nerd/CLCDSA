# coding: utf-8

import os, sys, re, string


def is_ugly(v):
    if v == 1:
        return 0
    if v == 0 or (v & 1) == 0 or (v % 3) == 0 or (v % 5) == 0 or (v % 7) == 0:
        return 1
    else:
        return 0

def main():
    count = int(sys.stdin.readline())
    def calculate(values):
        length = len(values)
        def g(va, v, i, valen):
            if i == valen - 1:
                return is_ugly(v)
            return g(va, v+va[i+1], i+1, valen) + g(va, v-va[i+1], i+1, valen)
        def f(va, i, result):
            if i == len(va) - 1:
                result.append(va)
                return
            f(va, i+1, result)
            f(va[:i] + [va[i]*10 + va[i+1]] + va[i+2:], i, result)
        arys = []
        f(values, 0, arys)
        return reduce(lambda x,y: x+y, [0] + map(lambda x: g(x, x[0], 0, len(x)), arys))
            
    for index in range(1, count+1):
        values = map(int, sys.stdin.readline().strip())
        print "Case #%d: %d" % (index, calculate(values))
        

if __name__ == '__main__':
    main()

