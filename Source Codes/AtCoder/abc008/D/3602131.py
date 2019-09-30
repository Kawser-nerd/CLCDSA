#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
https://beta.atcoder.jp/contests/abc008/tasks/abc008_2
"""

import sys
from inspect import currentframe
from itertools import permutations
import math
import numpy as np
from collections import namedtuple

sys.setrecursionlimit(100000)

def debug_print(*args):
    names = {id(v):k for k,v in currentframe().f_back.f_locals.items()}
    print(', '.join(names.get(id(arg),'???')+' = '+repr(arg) for arg in args), file=sys.stderr)


W, H = map(int, input().split())
N = int(input())
Point = namedtuple('Point', ['x', 'y'])
Area = namedtuple('Area', ['bottom_left', 'top_right'])
cranes = [Point(*map(int, input().split())) for _ in range(N)]
earn_memo = {}

def is_in_area(area, point):
    return area.bottom_left.x <= point.x < area.top_right.x and area.bottom_left.y <= point.y < area.top_right.y

import bisect
def in_area_points(area, sorted_points):
    min_x = bisect.bisect_left(sorted_points, area.bottom_left)
    max_x = bisect.bisect_right(sorted_points, area.top_right)
    in_x = sorted_points[min_x: max_x]
    # debug_print(in_x)
    return [point for point in in_x if area.bottom_left.y <= point.y < area.top_right.y]

# area?????????point=(x,y)?4????area???
# ??????area??????????????1-2??????
def split4(area, point):
    bl = area.bottom_left
    tr = area.top_right
    areas = [Area(Point(bl.x, bl.y), Point(point.x, point.y)),
             Area(Point(bl.x, point.y + 1), Point(point.x, tr.y)),
             Area(Point(point.x + 1, bl.y), Point(tr.x, point.y)),
             Area(Point(point.x + 1, point.y + 1), Point(tr.x, tr.y))]
    return list(filter(lambda a: a.bottom_left.x < a.top_right.x and a.bottom_left.y < a.top_right.y, areas))

def earn_gold(area, cranes):
    if area in earn_memo.keys():
        return earn_memo[area]
    earns = [0]
    #in_cranes2 = [crane for crane in cranes if is_in_area(area, crane)]
    in_cranes = in_area_points(area, cranes)
    # debug_print(area)
    # debug_print(in_cranes)
    # debug_print(in_cranes2)
    for crane in in_cranes:
        sub_areas = split4(area, crane)
        earn_this_split = (area.top_right.y - area.bottom_left.y) + (area.top_right.x - area.bottom_left.x) - 1
        earns.append(sum([earn_gold(sub_area, in_cranes) for sub_area in sub_areas]) + earn_this_split)
    earn = max(earns)
    earn_memo[area] = earn
    return earn

cranes.sort()

# import cProfile
# cProfile.run('earn_gold(Area(Point(1,1), Point(W + 1, H + 1)), cranes)')


print(earn_gold(Area(Point(1,1), Point(W + 1, H + 1)), cranes))