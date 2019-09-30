#!/Library/Frameworks/Python.framework/Versions/Current/bin/python

from math import sqrt
from collections import defaultdict

def opn():
    #return open('B-test.in.txt'), open('B-test.out', 'w')
    return open('B-small-attempt2.in.txt'), open('B-small.out', 'w')
    #return open('B-large.in.txt'), open('B-large.out', 'w')


def ugly(n):
    return (n % 2 == 0) or (n%3==0) or (n%5==0) or (n%7==0)
    

def main():
    
    f1, f2 = opn()

    runs = int(f1.readline()[:-1])

    for run in range(runs):
    
        number = f1.readline()[:-1]
        uglies=0
        
        results = [(number[-1],0)]
        ways = {results[0]:1}
        for i in reversed(number[:-1]):
            results, ways = expand(i, results, ways)
        results, ways = finish(results, ways)

        for i in results:
            if ugly(i):
                uglies+=ways[i]

        print >> f2, "Case #%d: %d" % (run+1, uglies)
        print "Case #%d: %d" % (run+1, uglies)

    
    f2.close()
    f1.close()


def expand(digit, all, ways):
    #print digit, all
    newlist = set()
    newways = defaultdict(int)
    for d,sum in all:
        newlist.add((digit, sum+int(d)))
        newlist.add((digit, sum-int(d)))
        newlist.add((digit+d, sum))
        newways[(digit, sum+int(d))] += ways[(d,sum)]
        newways[(digit, sum-int(d))] += ways[(d,sum)]
        newways[(digit+d, sum)] += ways[(d,sum)]
    return newlist, newways

def finish(all, ways):
    #print all
    newlist = set()
    newways = defaultdict(int)
    for d,sum in all:
        newlist.add(sum+int(d))
        #newlist.add(sum-d)
        newways[sum+int(d)] += ways[(d,sum)]
    #print newlist
    return newlist, newways
    


if __name__ == '__main__':
    main()
