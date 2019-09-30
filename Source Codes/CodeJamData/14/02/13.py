#!/usr/bin/env python
#coding=utf-8

def main():
    t=int(raw_input())
    for ti in range(t):
        c,f,x=map(float,raw_input().split())
        tim=0.0;p=2.0
        if x<=c:
            print "Case #%d: %.6f"%(ti+1,x/p)
            continue
        while (x/p)>(c/p+x/(p+f)):
            tim+=c/p
            p+=f
        print "Case #%d: %.7f"%(ti+1,tim+x/p)

if __name__=='__main__':
    main()

