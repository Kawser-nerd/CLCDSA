#!/usr/bin/python
''' Minimum Scalar Product
Google Code Jam 2008
Round 1A - Problem A
Grant Glouser <gglouser@gmail.com>
'''

import sys

def debug(*msg):
    DEBUG = not True
    if DEBUG:
        for x in msg[:-1]:
            print x,
        print msg[-1]

def read_int_line(f):
    return int(f.readline().rstrip())

def read_vector(f):
    v = f.readline().rstrip().split()
    return [int(x) for x in v]

def print_result(case_num, result):
    print 'Case #%d: %s' % (case_num, result)

def do_test_case(f, case_num):
    n = read_int_line(f)
    x = read_vector(f)
    debug(x)
    y = read_vector(f)
    debug(y)
    
    x.sort()
    y.sort()
    y.reverse()
    
    s = 0
    for i in range(n):
        s += x[i] * y[i]
    
    print_result(case_num, '%d' % s)

def main(input):
    f = file(input)
    n = read_int_line(f)
    for i in range(n):
        do_test_case(f, i+1)
    f.close()

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'usage: %s <input>' % sys.argv[0]
        sys.exit(1)
    main(sys.argv[1])
