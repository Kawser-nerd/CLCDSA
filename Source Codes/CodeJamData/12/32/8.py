#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
import sys
import math

infinite = 1E+9

class DiamondInheritance(object):

    def __init__(self):
        pass 

    @staticmethod
    def dist(v, a, t):
        return v*t + 0.5*a*(t**2)

    @staticmethod
    def modify(T, X ,D):
        if len(T) == 1 or X[0] >= D:
            return [T[0], infinite], [D, D]
        _X, _T = [], []
        for i in xrange(len(T)):
            if X[i] < D:
                _X.append(X[i])
                _T.append(T[i])
            else:
                v = (X[i]-X[i -1])/(T[i] - T[i-1])
                _T.append(T[i-1] + (D - X[i-1])/v)
                _X.append(D)
                _T.append(infinite)
                _X.append(D)
                break
        return _T, _X
            
    @staticmethod
    def quad(pos, v, a, x):
        delta = v**2 - 4*0.5*a*(pos - x)
        return (-v + math.sqrt(delta))/a
        
    def subsol(self, D, T, X, a):
        T, X = self.modify(T, X, D)
        v, pos, _t, _x = 0, 0, T[0], X[0] 
        for i, c in enumerate(zip(T[1:], X[1:]), 1):
            t, x = c
            if pos + self.dist(v, a, t - _t) >= x:
                __t = self.quad(pos, v, a, x)
                if i == len(T) - 1:
                    return _t + __t
                pos, v = x, v + __t*a 
            else:
                pos += self.dist(v, a, t - _t)
                v += a*(t - _t)
            _t, _x = t, x

    def sol(self, D, T, X , A):
        result = []
        for a_i in A:
            result.append(self.subsol(D, T, X, a_i))
        return result

def test_cases(input):
    fi = open(input, "r")
    T = int(fi.next())
    for i in xrange(1, T + 1):
        row = fi.next().split()
        D, N, A = float(row[0]), int(row[1]), int(row[2])
        t, x = [], []
        for j in xrange(N):
            row = fi.next().split()
            t.append(float(row[0]))
            x.append(float(row[1]))
        a = [float(v) for v in fi.next().split()]
        yield i, D, N, A, t, x, a
    fi.close()

def main(input, output):
    fo = open(output, "w")
    problem = DiamondInheritance()
    for i, D, N, A, t, x, a in test_cases(input):
        result = problem.sol(D, t, x, a)
        fo.write("Case #{0}:\n".format(i))
        for t in result:
            fo.write("%.7f\n" % t) 
    fo.close()
        
if __name__ == "__main__":
    # Parse command options
    from optparse import OptionParser
    parser = OptionParser(usage="Usage: %prog [options] param1 param2")    
    parser.add_option("-i", "--input", dest="input", help="Input file")
    parser.add_option("-o", "--output", dest="output", help="Output file")
    options, args = parser.parse_args()
    main(options.input, options.output)
