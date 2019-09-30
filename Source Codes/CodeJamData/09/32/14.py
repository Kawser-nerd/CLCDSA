from gcjt import *
from math import sqrt
for t in tests():
      n = int(t.rl())
      a = [0]*6
      for i in range(n):
            aa = tuple(t.ri())
            for i in range(6):
                  a[i]+=aa[i]
      for i in range(6):
            a[i]/=n
      x,y,z,vx,vy,vz = a
      d = vx**2+vy**2+vz**2
      if d == 0:
            tt=0
      else:
            tt = - (x*vx+y*vy+z*vz)/(vx**2+vy**2+vz**2)
            if tt<0: tt=0
      x,y,z = x+vx*tt,y+vy*tt,z+vz*tt
      s = sqrt(x**2+y**2+z**2)
      t.answer('{0:.8f} {1:.8f}'.format(s,tt))

      
