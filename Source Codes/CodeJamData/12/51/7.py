#!/usr/bin/env python

def main():
    T = input()
    for t in range(1, T + 1):
        n = input()
        l = map(int, raw_input().split())
        p = map(int, raw_input().split())
        a = zip(l, p, range(n))
        a.sort(lambda x, y: x[0] * y[1] - x[1] * y[0])
        print 'Case #%d:' % t,
        for x in a:
            print x[2],
        print

if __name__ == '__main__':
    main()
