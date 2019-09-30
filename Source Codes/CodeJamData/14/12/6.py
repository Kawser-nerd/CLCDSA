#!/usr/bin/env python3

from collections import defaultdict

def rl(t):
    return [ t(_) for _ in input().split() ]

def solve( n, edges ):
    e = [ [] for i in range(n) ]
    for a,b in edges:
        e[a-1].append(b-1)
        e[b-1].append(a-1)

    def f( i, p ):

        childs = [ j for j in e[i] if j != p ]
        
        if len(childs) < 2:
            res = 1
        else:
            d = [ f(j,i) for j in childs ]
            d.sort( reverse = True )
            res = d[0] + d[1] + 1
        
        #print(i,p,res)
        return res

    ds = [ f(root,-1) for root in range(n) ]

    return n - max(ds)

def main():
    T, *_ = rl(int)
    for C in range(1,T+1):
        n, *_ = rl(int)

        edges = []
        for i in range(n-1):
            a,b = rl(int)
            edges.append( (a,b) )

        answer = solve(n, edges)
        print('Case #%d:'%C, answer)


if __name__ == '__main__':
    main()
