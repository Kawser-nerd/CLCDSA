#!/usr/bin/env python
#coding=utf-8

def main():
    t=int(raw_input())
    for ti in range(t):
        n=int(raw_input())
        l1=map(float,raw_input().split())
        l2=map(float,raw_input().split())
        l1.sort();l2.sort()
        l3=l2[:];l4=l1[:]
        y=0
        for li in l1:
            if li<l3[0]:
                del l3[-1]
            else:
                del l3[0]
                y+=1
        for li in l2:
            if li>l4[0]:
                del l4[0]
        z=len(l4)
        print "Case #%d: %d %d"%(ti+1,y,z)

if __name__=='__main__':
    main()

