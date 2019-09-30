# -*- coding: utf-8 -*-
import math

fin = open("b.in","r")
T = int(fin.readline())

def size(v):
    return math.sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2])
    
for i in range(T):
    N = int(fin.readline())
    
    px = 0.0
    py = 0.0
    pz = 0.0
    
    vx = 0.0
    vy = 0.0
    vz = 0.0
    
    for j in range(N):
        x, y, z, xx, yy, zz = map(int, fin.readline().split())
        px += x
        py += y
        pz += z
        vx += xx
        vy += yy
        vz += zz
        
    px /= N
    py /= N
    pz /= N
    vx /= N
    vy /= N
    vz /= N
    
    #print px, py, pz, vx, vy, vz
    dotp = - (px*vx + py*vy + pz*vz)
    bs = size((vx,vy,vz))
    if bs == 0:
        time = -1
    else:
        dist = dotp/bs
        cross = (vx/bs*dist + px, vy/bs*dist + py, vz/bs*dist + pz)
        time = dist/bs
    if time < 0:
        time = 0
        cross = (px, py, pz)
    
    print "Case #%d: %.8f %.8f" % (i+1,  size(cross), time)
    
    
    