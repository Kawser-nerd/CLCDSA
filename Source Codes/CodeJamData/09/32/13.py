import sys
import math

fin=open('input.txt','r')
fout=open('output.txt','w')

l=int(fin.readline())
for case in range(l):
    N=int(fin.readline())
    px,py,pz=0.0,0.0,0.0
    vx,vy,vz=0.0,0.0,0.0
    
    for i in range(N):
        ix,iy,iz,ivx,ivy,ivz=map(float,fin.readline().strip().split())
        px+=ix
        py+=iy
        pz+=iz
        
        vx+=ivx
        vy+=ivy
        vz+=ivz
    
    px/=N
    py/=N
    pz/=N
    
    vx/=N
    vy/=N
    vz/=N
    
    if vx==0 and vy==0 and vz==0:
        fout.write("Case #%d: %.8f 0.00000000\n"%(case+1,math.pow(px*px+py*py+pz*pz,0.5)))
        continue
    
    t=(-px*vx-py*vy-pz*vz)/(vx*vx+vy*vy+vz*vz)
    if t<0:
        fout.write("Case #%d: %.8f 0.00000000\n"%(case+1,math.pow(px*px+py*py+pz*pz,0.5)))
        continue
    else:
        px+=vx*t
        py+=vy*t
        pz+=vz*t
        fout.write("Case #%d: %.8f %.8f\n"%(case+1,math.pow(px*px+py*py+pz*pz,0.5),t))
    
fin.close()
fout.close()
