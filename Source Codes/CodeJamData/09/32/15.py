from __future__ import division
from math import sqrt

# code jam template
filein="B.in"
fileout="B.out"

def solve(caseid,flydata):
    num=len(flydata)
    X=Y=Z=DX=DY=DZ=0
    for i in range(num):
        x,y,z,dx,dy,dz=map(float,flydata[i].split(' '))
        X+=x
        Y+=y
        Z+=z
        DX+=dx
        DY+=dy
        DZ+=dz
    X=X/num
    Y=Y/num
    Z=Z/num
    DX=DX/num
    DY=DY/num
    DZ=DZ/num
    try:
        t=max(0,-(X*DX+Y*DY+Z*DZ)/(DX*DX+DY*DY+DZ*DZ))
    except:
        print DX,DY,DZ
        t=0
    px,py,pz=(X+t*DX,Y+t*DY,Z+t*DZ)
    minD=sqrt(px**2+py**2+pz**2)
    return 'Case #%d: %.8f %.8f' % (caseid,minD,t)
            

# load data
# paste basic example
datain="""
3
3
3 0 -4 0 0 3
-3 -2 -1 3 0 0
-3 -1 2 0 3 0
3
-5 0 0 1 0 0
-7 0 0 1 0 0
-6 3 0 1 0 0
4
1 2 3 1 2 3
3 2 1 3 2 1
1 0 0 0 0 -1
0 10 0 0 -10 -1
"""
#or
datain=open(filein).read()
dataout=open(fileout,"w")

# data as lines of data
data=[x for x in datain.split('\n') if x]
N=int(data[0])
atrow=1
for case in range(N):
    flies=int(data[atrow])
    flydata=data[atrow+1:atrow+flies+1]
    text=str(solve(case+1,flydata))

    print text
    dataout.write(text+'\n')
    atrow+=flies+1



# close data file
dataout.close()
print "Wrote %s" % fileout



