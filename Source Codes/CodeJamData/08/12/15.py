#! /usr/bin/python

import sys

def main():
    cin=sys.stdin
    for _ in xrange(int(cin.readline())):
        milk=int(cin.readline())
        cust=int(cin.readline())

        fav=[]
        for c in xrange(cust):
            l=[int(x) for x in cin.readline().strip().split()]

            m=[]
            u=[]
            for i in xrange(l[0]):
                x, y=l[2*i+1]-1,l[2*i+2]
                if y==1:
                    # malted
                    m.append(x)
                else:
                    u.append(x)
            fav.append((m,u))


        done=[False]*cust
        malt=[0]*milk
        impossible=False
        while 1:
            change=False
            for c in xrange(cust):
                if not done[c]:
                    m, u=fav[c]
                    if m and malt[m[0]]:
                        done[c]=True
                        continue
                    if (not u) or all([malt[i]==1 for i in u]):
                        if not m:
                            impossible=True
                            break
                        malt[m[0]]=1
                        done[c]=True
                        change=True
            if (not change) or impossible:
                break

        print 'Case #%d:'%(_+1),
        if impossible:
            print 'IMPOSSIBLE'
        else:
            for i in malt:
                print i,
            print

if __name__=="__main__":
    main()
