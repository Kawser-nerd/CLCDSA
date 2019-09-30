import math
p = float(input())
x = 1.5*math.log2(math.log(2)*p/1.5)
if x<0:
  print(p)
else:
  print(x+1.5/math.log(2))