from sys import *
from heapq import *
import math

def write(msg):
    stdout.write(msg)
    fo.write(msg)

def writeln(msg):
    write(str(msg) + '\n')

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def readstr():
    return fi.readline().rstrip()

fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])
fi = open(fni, 'r')
fo = open(fno, 'w')

def ffail(start, step, num, prizes):
    if prizes >= num:
        return start + step*(num-1) + 1
    if prizes <= 0:
        return start
    if 2*prizes <= num:
        return start + step
    return ffail(start+step, step*2, num/2, prizes-num/2)

def wwin(start, step, num, prizes):
    if prizes >= num:
        return start + step*(num-1)
    if prizes <= 0:
        return 0
    return wwin(start, step*2, num/2, prizes)

num_cases = readint()
for case in range(1, 1+num_cases):
    (N, P) = readints()
    g = ffail(0,1,2**N,P)-1
    w = wwin(0,1,2**N,P)
    writeln("Case #%d: %d %d" % (case, g, w))

