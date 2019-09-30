#!/usr/bin/python

# google code jam - c.durr - 2009

# center of mass
# c = avr center of fireflies
# v = avr velocity
# e = avr center at time 1

from math import sqrt

def dot(a,b):
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2]

def sub(a,b):
    return (a[0]-b[0], a[1]-b[1], a[2]-b[2])

def add(a,b):
    return (a[0]+b[0], a[1]+b[1], a[2]+b[2])

def mul(a, f):
    return (a[0]*f, a[1]*f, a[2]*f)

def norm22(a):
    return dot(a,a)

T = int(raw_input())
for t in range(T):
    x,y,z = 0,0,0
    vx,vy,vz = 0,0,0
    n = int(raw_input())
    for i in range(n):
        xi, yi, zi, vxi, vyi, vzi = map(int, raw_input().split())
        x = x+xi
        y = y+yi
        z = z+zi
        vx = vx+vxi
        vy = vy+vyi
        vz = vz+vzi
        
    c = mul((x,y,z), 1./n)
    v = mul((vx,vy,vz), 1./n)

    b = dot(v,v)
    
    if b==0:
        tmin = 0
    else:
        tmin = - dot(c, v) / b
        if tmin<0:
            tmin = 0

    d2 = norm22(add(c, mul(v, tmin)))
     
    print "Case #%i:"% (t+1), sqrt(d2), tmin
    
