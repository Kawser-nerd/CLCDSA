#!/usr/bin/env python
#coding=utf-8

from math import *

sample = """5
0.25 1.0 0.1 0.01 0.5
0.25 1.0 0.1 0.01 0.9
0.00001 10000 0.00001 0.00001 1000
0.4 10000 0.00001 0.00001 700
1 100 1 1 10"""


def area(r,x,y,d):
    R = lambda p: sqrt(p[0]**2+p[1]**2)
    p1 = [x-d,y-d]
    p2 = [x+d,y-d]
    p3 = [x+d,y+d]
    p4 = [x-d,y+d]
    if R(p1) >= r:
        return 0
    elif R(p2) >= r:
        p12 = [sqrt(r**2-(y-d)**2),y-d]
        p14 = [x-d,sqrt(r**2-(x-d)**2)]
        phi = atan(p14[1]/p14[0])-atan(p12[1]/p12[0])
        a = (r**2*phi-r**2*sin(phi))/2.
        a += (p12[0]-p1[0])*(p14[1]-p1[1])/2.
        return a
    elif R(p4) >= r:
        p23 = [x+d,sqrt(r**2-(x+d)**2)]
        p14 = [x-d, sqrt(r**2-(x-d)**2)]
        phi = atan(p14[1]/p14[0])-atan(p23[1]/p23[0])
        a = (r**2*phi-r**2*sin(phi))/2.
        a += (p14[1]-p1[1]+p23[1]-p2[1])*d
        return a
    elif R(p3) >= r:
        p23 = [x+d,sqrt(r**2-(x+d)**2)]
        p34 = [sqrt(r**2-(y+d)**2),y+d]
        phi = atan(p34[1]/p34[0])-atan(p23[1]/p23[0])
        a = (r**2*phi-r**2*sin(phi))/2.
        a += 4*d**2 - (p3[0]-p34[0])*(p3[1]-p23[1])/2.
        return a
    else:
        return 4*d**2
        
infile = iter(sample.split('\n'))
infile = open("C-large.in",'r')
outfile = open("C-large.out",'w')

N = int(infile.next().strip())
for n in xrange(N):
    f,R,t,r,g = [float(x) for x in infile.next().strip().split()]
    AA = pi*R**2/8.
    gg = g-2*f
    rr = r+f
    RR = R-t-f
    dd = 2*rr+gg
    p = 0
    if gg <= 0 or RR <= 0:
        p = 1.
    else:
        ii = RR/(sqrt(2)*dd)
        aoh = 0
        for i in xrange(int(floor(ii))):
            aoh += gg*gg/2.
            LL = sqrt(RR**2-((i+1)*dd)**2)-(i+1)*dd
            k = floor(LL/dd)
            aoh += k*gg*gg
            xx = (i+1)*dd-dd/2
            yy = xx+(k+1)*dd
            ta = area(RR,xx,yy,gg/2)
            while ta != 0:
                aoh += ta
                yy += dd
                ta = area(RR,xx,yy,gg/2)
        cii = ceil(ii)
        if cii != ii:
            xx = cii*dd-dd/2
            yy = xx
            ta = area(RR,xx,yy,gg/2)/2.
            while ta != 0:
                aoh += ta
                yy += dd
                ta = area(RR,xx,yy,gg/2)
        #print aoh,AA
        p = 1.-aoh/AA
    print "Case #%d: %1.6f"%(n+1,p)
    outfile.write("Case #%d: %1.6f\n"%(n+1,p))

infile.close()
outfile.close()
                
            
            
            
    
