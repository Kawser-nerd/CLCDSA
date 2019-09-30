import sys

def main(ifn='ain.txt',ofn='aout.txt'):
    sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n,p,q,r,s = map(int,inf.readline().strip().split(' '))
                aa = [(x*p+q)%r+s for x in xrange(n)]
                a = [x for x in aa if x!=0]
                n = len(a)
                sum0 = [0]*(n+1)
                sum1 = [0]*(n+1)
                for i in xrange(n):
                    sum0[i+1] = sum0[i]+a[i]
                for i in xrange(n-1,-1,-1):
                    sum1[i] = sum1[i+1]+a[i]
                allv = sum0[-1]
                bestAnswer = allv
                j = 0
                for i in xrange(n+1):
                    if sum0[i]>=allv:
                        break
                    ps = allv-sum0[i]
                    j = max(j-1,i)
                    while j<=n:
                        v1 = sum1[j]
                        tmp = max(sum0[i],v1,ps-v1)
                        if tmp<bestAnswer:
                            bestAnswer = tmp
                            #print"max = %d, v = %s" %(tmp,[sum0[i],ps-v1,v1])
                        if float(v1)>ps/2.0:
                            j += 1
                        else:
                            break
                answer = 1.-float(bestAnswer)/float(allv)
                print "%.12lf" %(answer)
                ouf.write("%.12lf\n" %(answer))

