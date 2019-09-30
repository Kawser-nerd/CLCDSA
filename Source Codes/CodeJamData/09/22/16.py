#!/usr/bin/python

from sys import stdin, stdout, stderr
from collections import defaultdict

def read_int(strLine):
    return map(int,
               strLine.split(' '))

def read_string(strLine):
    return strLine.split(' ')

def read_float(strLine):
    return map(float,
               strLine.split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')


def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        digits = map(lambda x: int(x), rsreadline())
        if len(digits) == 1:
            print 'Case #%d: %s' % (iCase + 1, digits[0]*10)
            continue
        digits.reverse()
        h = defaultdict(lambda: 0)
        for i in xrange(0, len(digits)-1):
            if digits[i+1] >= digits[i]:
                h[digits[i]] += 1
            else:
                h[digits[i]] += 1
                break
        else:
            h[digits[i+1]] += 1
            h[0] += 1
            st = ""
            m = str(min(filter(lambda x: x!=0, h)))
            st += m
            h[int(m)] -= 1
            if h[int(m)] == 0:
                del h[int(m)]
            for c in sorted(h):
                for q in xrange(0, h[c]):
                    st += str(c)
            print 'Case #%d: %s' % (iCase + 1, st)
            stdout.flush()
            continue
        i += 1
        k = min(filter(lambda x: x>digits[i], h))
        h[k] -= 1
        if h[k] == 0:
            del h[k]
        h[digits[i]] += 1
        digits[i] = k
        j = i-1
        for c in sorted(h):
            for q in xrange(0, h[c]):
                digits[j] = c
                j -= 1
        digits.reverse();
        st = ""
        for i in digits:
            st += str(i)
        print 'Case #%d: %s' % (iCase + 1, st)
        stdout.flush()

main()
