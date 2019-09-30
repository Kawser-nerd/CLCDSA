#! /usr/bin/python

import sys

def main():
    cin=sys.stdin
    for _ in xrange(int(cin.readline())):
        n=int(cin.readline())
        v1=[int(x) for x in cin.readline().strip().split()]
        v2=[int(x) for x in cin.readline().strip().split()]        

        v1.sort()
        v2.sort()
        h1=h2=0
        t1=t2=n-1

        val=0
        while h1<=t1 and t2>=h2 and v1[h1]<=0 and v2[t2]>=0:
            val+=v1[h1]*v2[t2]
            h1+=1
            t2-=1
        while h1<=t1 and h2<=t2 and v2[h2]<=0 and v1[t1]>=0:
            val+=v2[h2]*v1[t1]
            h2+=1
            t1-=1
        assert ((not (h1<=t1 and h2<=t2)) or
                ((v1[t1]<0 and v2[t2]<0) or (v1[h1]>0 and v2[h2]>0)))
        
        while h1<=t1 and h2<=t2:
            val+=v1[h1]*v2[t2]
            h1+=1
            t2-=1

        print 'Case #%d:'%(_+1), val
        
if __name__=="__main__":
    main()
