#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Graham Dennis on 2010-05-08.
Copyright (c) 2010 __MyCompanyName__. All rights reserved.
"""

import sys


def main(argv=None):
    if argv is None:
        argv = sys.argv
    f = file(sys.argv[1])
    
    T = int(f.readline())
    for t in xrange(T):
        N, K = map(int, f.readline().split())
        result = 'ON' if (K % (2**N)) == 2**N - 1 else 'OFF'
        print 'Case #%i: %s' % (t+1, result)
    


if __name__ == "__main__":
    sys.exit(main())
