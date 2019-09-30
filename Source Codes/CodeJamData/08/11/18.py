#!/usr/bin/python

import sys, math

def dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return pyth(x2-x1,y2-y1)

def pyth(s1,s2):
    return math.sqrt(math.pow(s1,2) + math.pow(s2,2))

def cArea(r):
    return math.pi * math.pow(r,2)

def rectArea(l, w):
    return l * w

def triArea(s1, s2, s3):
    s = (s1 + s2 + s3) / 2
    return s  * (s-s1) * (s-s2) * (s-s3)


def main(v1,v2):
    v1.sort()
    v2.sort(lambda a,b: cmp(b,a))

    sum = 0
    for i in range(len(v1)):
        sum += (v1[i] * v2[i])
    return sum


def getline(fpin, types):
    args = fpin.readline().strip().split()
    for i in range(len(types)):
        args[i] = types[i](args[i])
    return args


if __name__=="__main__":
    fpin=open(sys.argv[1])
    if len(sys.argv) > 2:
        fpout = open(sys.argv[2], 'w')
    else:
        fpout = sys.stdout


    cases = int(fpin.readline().strip())
    for case in range(1,cases+1):
        s = int(fpin.readline().strip())
        v1 = [int(x) for x in fpin.readline().strip().split()]
        v2 = [int(x) for x in fpin.readline().strip().split()]
        fpout.write("Case #%d: %s\n" % (case, main(v1,v2) ))

