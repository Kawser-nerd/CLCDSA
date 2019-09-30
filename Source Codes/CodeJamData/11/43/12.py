from operator import itemgetter
fi = open("input.txt")
maxn = 10**6+100
#primes
a = [1]*maxn
primes = []
for i in range(2,maxn):
    if a[i]==1:
        primes.append(i)
        j = i+i
        while j<maxn:
            a[j] = 0
            j+=i

for run in range(int(fi.readline())):
    res = 0
    n = int(fi.readline())
    for p in primes:
        if p*p>n:
            break
        p2 = p*p
        while p2<=n:
            res+=1
            p2*=p
            #print p2
        #print p,res
    if n==1:
        res = -1
    print "Case #{0}: {1}".format(run+1,res+1)
                    