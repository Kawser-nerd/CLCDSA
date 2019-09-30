#!/usr/bin/env python
#coding=utf-8

def main():
    t=int(raw_input())
    for ti in range(t):
        ans1=int(raw_input())
        l1=[]
        for i in range(4):
            l1.append(map(int,raw_input().split()))
        l2=[]
        ans2=int(raw_input())
        for i in range(4):
            l2.append(map(int,raw_input().split()))
        s=set(l1[ans1-1]).intersection(set(l2[ans2-1]))
        if len(s)==1:
            print "Case #%d: %d"%(ti+1,list(s)[0])
        elif s==set():
            print "Case #%d: Volunteer cheated!"%(ti+1)
        else:
            print "Case #%d: Bad magician!"%(ti+1)

if __name__=='__main__':
    main()

