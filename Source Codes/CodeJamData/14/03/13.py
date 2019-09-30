#!/usr/bin/env python
#coding=utf-8

def pm(l,tf):
    if tf:
        ln=zip(*l)
    else:
        ln=l
    for li in ln:
        print ''.join(li)

def main():
    t=int(raw_input())
    for ti in range(t):
        print "Case #%d:"%(ti+1)
        r,c,m1=map(int,raw_input().split())
        m=r*c-m1
        if r>c:
            r,c=c,r
            tf=1
        else:
            tf=0
        if r==1:
            l=[['c']+['.']*(m-1)+['*']*(c-m)]
            pm(l,tf)
        elif r==2:
            if m==1:
                l=[['c']+['*']*(c-1),['*']*c]
                pm(l,tf)
            elif m%2==1 or m==2:
                print "Impossible"
            else:
                l=[['c']+['.']*(m/2-1)+['*']*(c-m/2),['.']*(m/2)+['*']*(c-m/2)]
                pm(l,tf)
        elif m==1:
            l=[]
            for ri in range(r):
                l.append(['*']*c)
            l[0][0]='c'
            pm(l,tf)
        elif m==2 or m==3 or m==5 or m==7:
            print "Impossible"
        else:
            if m>=r*2:
                r1=r
                c1=m/r
            else:
                r1=m/2
                c1=2
            y1=m-r1*c1;y2=0
            if y1==1:
                if c1==2:
                    r1-=1
                    y1+=2
                else:
                    y1+=1
                    y2=1
            l1=[]
            for ri in range(r1):
                l1.append(['.']*(c1+1 if ri<y1 else c1))
            l1[0][0]='c'
            if y2:
                del l1[-1][-1]
            l=[]
            for ri in range(r):
                if ri<r1:
                    l.append(l1[ri]+['*']*(c-len(l1[ri])))
                else:
                    l.append(['*']*c)
            pm(l,tf)

if __name__=='__main__':
    main()

