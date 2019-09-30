import sys
import psyco

def primes(n): 
    if n==2: return [2]
    elif n<2: return []
    s=range(3,n+1,2)
    mroot = n ** 0.5
    half=(n+1)/2-1
    i=0
    m=3
    while m <= mroot:
        if s[i]:
            j=(m*m-3)/2
            s[j]=0
            while j<half:
                s[j]=0
                j+=m
        i=i+1
        m=2*i+3
    return [2]+[x for x in s if x]

def maxprimeFactors(n): 
    if n==1: return 1
    if n==2: return 2
    s=range(3,n+1,2)
    mroot = n ** 0.5
    half=(n+1)/2-1
    i=0
    m=3
    while m <= mroot:
        if s[i]:
            j=(m*m-3)/2
            s[j]=0
            while j<half:
                s[j]=0
                j+=m
        i=i+1
        m=2*i+3
    return max([2]+[x for x in s if x and n%x==0])

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def solve(a,b,p):
    #primelist = primes(b)
    interval = range(a, b + 1)
    intervalset = [set([i]) for i in interval]
    n = len(interval)
    for i,j in enumerate(interval):
        for k in range(i + 1, n):
            if maxprimeFactors(gcd(j, interval[k])) >= p:
                #merge two sets
                for ii,jj in enumerate(intervalset):
                    if interval[k] in jj:
                        indexk = ii
                    if j in jj:
                        indexj = ii
                if indexk != indexj:
                    intervalset[indexj] = intervalset[indexj].union(intervalset[indexk])
                    intervalset.pop(indexk)
    return len(intervalset)

def main():
    file = open(sys.argv[1], 'r')
    nc = int(file.readline())

    count = 1
    for line in file:
        a, b, p = [int(i) for i in line.split()]
        out = solve(a, b, p)
        print 'Case #' + str(count) + ':', out
        count += 1

if __name__ == "__main__":
    #g = psyco.proxy(main)
    #g()
    main()
