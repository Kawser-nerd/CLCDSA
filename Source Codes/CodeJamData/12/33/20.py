'''
Created on May 5, 2012

@author: Indra
'''
import sys, os

#filename = "A-large"
filename = "C-large"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".out"))
writer = open(path, "w")
T = int(reader.readline().rstrip())
N, M = 0, 0
lA, lB = [], []

def getMatch(a, b):
    if a[1] > b[1]:
        return b[1]
    else:
        return a[1]

def getExtra(a, b):
#    print "extra:::", a, " - ", b
    if a[1] == b[1]:
        return None
    if a[1] > b[1]:
        return (True, a[1] - b[1], a[2])
    else:
        return (False, b[1] - a[1], b[2])
    
def mymax(a, b):
    if a > b:
        return a
    else:
        return b

#(isBox, count, type)

visited = {}

def getBest(n, m, leftover):
#    print "getBest:",n," ",m," ",leftover
    key = (n,m,leftover)
    if visited.has_key(key):
        return visited[key]
    best = 0
    if not leftover:
        if n < 0 or m < 0:
            return 0
    else:
        if leftover[0] and m<0:
            return 0
        if (not leftover[0]) and n<0:
            return 0
            
    nextn = n
    nextm = m
    if leftover:
        if leftover[0]:
            curA = leftover
            curB = lB[m]
            nextm -= 1
        else:
            curA = lA[n]
            curB = leftover
            nextn -= 1
    else:
        curA = lA[n]
        curB = lB[m]
        nextn -= 1
        nextm -= 1
#    print curA
#    print curB
    if curA[2] == curB[2]:
        best = mymax(best, getMatch(curA, curB) + getBest(nextn, nextm, getExtra(curA, curB)))
    else:
        best = mymax(best, getBest(nextn, nextm, curA))
        best = mymax(best, getBest(nextn, nextm, curB))
    visited[key]=best
    return best
        

caseno = 1
while caseno <= T:
    N, M = [int(x) for x in reader.readline().rstrip().split(' ')]
    line = reader.readline().rstrip()
    t = [int(x) for x in line.split(' ')]
    lA = [(True, t[2 * i], t[2 * i + 1]) for i in xrange(N)]
    line = reader.readline().rstrip()
    t = [int(x) for x in line.split(' ')]
    lB = [(False, t[2 * i], t[2 * i + 1]) for i in xrange(M)]
    print lA
    print lB
    
    visited = {}
    ret = getBest(N - 1, M - 1, None)
    
    pret = str(ret)
    writer.write("Case #%s: %s\n" % (str(caseno), pret))
    caseno += 1

writer.close()
