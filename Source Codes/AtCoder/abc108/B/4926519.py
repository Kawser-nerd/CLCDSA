import numpy as np

x1, y1, x2, y2 =map(int, input().split())  #??????

x3 = y1-y2+x2
y3 = x2-x1+y2
x4 = y1-y2+x1
y4 = x2-x1+y1

L = [x3,y3,x4,y4]
print(' '.join(map(str, L)))