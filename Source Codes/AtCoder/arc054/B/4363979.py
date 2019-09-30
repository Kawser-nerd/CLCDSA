import math
P = float(input())
x = (-1.5)*(math.log(1.5/(P*math.log(2))))/math.log(2)
if x > 0:
  print(x+P/(2**(x/1.5)))
else:
  print(P)