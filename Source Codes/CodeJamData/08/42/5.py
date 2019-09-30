#! /usr/bin/python

import psyco
import sys
psyco.profile()


def main():
    rl=sys.stdin.readline
    for t in xrange(int(rl())):
        n, m, a=[int(x) for x in rl().strip().split()]

        ans=False
        val={}
        for x in xrange(0,n+1):
            for y in xrange(0,m+1):
                if x*y not in val:
                    val[x*y]=(x,y)
                    
        for x in xrange(1,n+1):
            for y in xrange(a/x,m+1):
                if x*y<a:
                    continue
                if x*y-a in val:
                    v=val[x*y-a]
                    ans=(0,0,x,v[1],v[0],y)
                    break
            if ans:
                break
        print 'Case #%d:'%(t+1),
        if ans:
            for i in ans:
                print i,
        else:
            print 'IMPOSSIBLE',
        print


main()
