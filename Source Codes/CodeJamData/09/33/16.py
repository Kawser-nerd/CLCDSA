from gcjt import *
for t in tests():
      p,q = tuple(t.ri())
      x = (0,)+tuple(t.ri())+(p+1,)
      f = array(q+2,q+2)
      for i in range(0,q+1):
            f[i][i+1] = 0
      for l in range(2,q+2):
            for i in range(q+2-l):
                  f[i][i+l] = x[i+l]-x[i]-2+\
                        min(f[i][j]+f[j][i+l] for j in range(i+1,i+l))
      t.answer(f[0][q+1])
