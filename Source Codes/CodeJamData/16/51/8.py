#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

class Stack(object):
    def __init__(self, N):
        self.a = ['X'] * N
        self.n = 0

    def push(self, x):
        self.a[self.n] = x
        self.n += 1

    def top(self):
        return self.a[self.n-1]

    def pop(self):
        self.n -= 1
        return self.a[self.n]


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        s = sys.stdin.readline().strip()
        ret = 0
        st = Stack(len(s))
        for x in s:
            if st.n and st.top() == x:
                ret += 10
                st.pop()
            else:
                st.push(x)

        ret += 5 * st.n/2
        print "Case #%d: %s" % (t, ret)

if __name__ == '__main__':
    main()
