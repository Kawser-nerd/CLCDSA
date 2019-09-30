#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
import sys

sys.setrecursionlimit(10000)

class DiamondInheritance(object):
 
    def __init__(self):
        pass 

    def exists(self, N, children, K):

        visited = [0]*(N + 1)

        def visit(node):
            if visited[node]==1: 
                if node != K: return True
                else: return False

            visited[node] = 1
            for c in children[node]:
                if visit(c): return True
            return False

        return visit(K) 

    def sol(self, N, children):
        for i in xrange(1, N + 1):
            if self.exists(N, children, i):
                return True
        return False

def test_cases(input):
    fi = open(input, "r")
    T = int(fi.next())
    for i in xrange(1, T + 1):
        N = int(fi.next())
        children = [[]]
        for j in xrange(N):
            row = [int(x) for x in fi.next().split(" ")]
            children.append(row[1:])
        yield i, N, children
    fi.close()

def main(input, output):
    fo = open(output, "w")
    problem = DiamondInheritance()
    for i, N, children in test_cases(input):
        result = problem.sol(N, children)
        print N, children
        fo.write("Case #{0}: {1}\n".format(i, "Yes" if result else "No")) 
    fo.close()
        
if __name__ == "__main__":
    # Parse command options
    from optparse import OptionParser
    parser = OptionParser(usage="Usage: %prog [options] param1 param2")    
    parser.add_option("-i", "--input", dest="input", help="Input file")
    parser.add_option("-o", "--output", dest="output", help="Output file")
    options, args = parser.parse_args()
    main(options.input, options.output)
