import math;
from collections import namedtuple

ax, ay, bx, by, cx, cy = (int(i) for i in input().split())

Vec = namedtuple('vector', ('x y'));

ab = Vec(bx - ax, by - ay);
ac = Vec(cx - ax, cy - ay);

print(abs(ab.x * ac.y - ab.y * ac.x) / 2);