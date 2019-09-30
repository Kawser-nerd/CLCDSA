#!/usr/bin/python

import sys, math

prec = 100

def sqr(s):
    (sa, sb) = s.split('.')
    s = int(sa+sb)
    s = str(s*s)
    e = 2*len(sb)
    sa,sb = s[:-e],s[-e:]
    sa = sa[-prec:]
    sb = sb[:prec]
    return sa+'.'+sb
def time(s,t):
    (sa, sb) = s.split('.')
    (ta, tb) = t.split('.')
    s = int(sa+sb)
    t = int(ta+tb)
    s = str(s*t)
    e = len(sb) + len(tb)
    sa,sb = s[:-e],s[-e:]
    sa = sa[-prec:]
    sb = sb[:prec]
    return sa+'.'+sb



the_number = '5.23606797749978969640917366873127623544061835961152572427089724541052092563780489941441440837878227496950817615077378350425326772444707386358636012153'

t = ['0001.000000',the_number]

def init():
    a = the_number
    for i in range(34):
#        print i,a
        a = sqr(a)
        t.append(a)

def calculate(n):
    pow = 1
    ret = '0001.00000'
    while n:
        if (n%2):
            ret = time(ret,t[pow])
#            print ret
        n = n/2
        pow = pow+1
    ra,rb = ret.split('.')
    ret = ra[-3:]
    while len(ret)<3:
        ret = '0'+ret
    return ret


def run():
    init()
    file = open(sys.argv[1],'r')
    laps = int( file.next())
    for lap in range(1,laps+1):
        n = int(file.next())
        print "Case #%d: %s" % (lap, calculate(n))


run()
