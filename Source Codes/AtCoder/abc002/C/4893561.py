from operator import itemgetter
import numpy as np
from math import atan, cos, sin
x1,y1,x2,y2,x3,y3 = map(int, input().split())
# x ????
xy = [(x1,y1), (x2,y2), (x3,y3)]
xy.sort(key=itemgetter(1))
xy.sort(key=itemgetter(0))

x1,y1 = xy[0]
x2,y2 = xy[1]
x3,y3 = xy[2]
if x2-x1 == 0:
    x2,x3 = x3,x2
    y2,y3 = y3,y2
theta = atan((y2-y1)/(x2-x1))
# print(theta)

def rotate(x,y,theta,a,b):
    """ (x,y) ? (a,b) ??? thera ??"""
    rot = np.array([[cos(theta), -sin(theta)],
                    [sin(theta), cos(theta)]])
    pos = np.dot(rot, np.array([[x-a], [y-b]]))
    return pos[0][0]+a, pos[1][0]+b

x2,y2 = rotate(x2,y2, -theta, x1,y1)
x3,y3 = rotate(x3,y3, -theta, x1,y1)
# print(x1, y1)
# print(x2, y2)
width = x2-x1
height = y3-y1
print(abs(1/2 * width * height))