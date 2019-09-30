#!/usr/bin/env python3

from itertools import *
from collections import *
from functools import *
from operator import add
from math import *
import pycosat
# from operator import 
# hint: dir(operator)

def vectoradd(a, b):
    return tuple(map(add, a, b))

interpretSlash = {"/":  {(0, 1): (-1, 0), (1, 0): (0, -1), (-1, 0): (0, 1), (0, -1): (1, 0)},
                  "\\": {(0, 1): (1, 0), (-1, 0): (0, -1), (1, 0): (0, 1), (0, -1): (-1, 0)},
                  }

interpretBeamer = {1:  [(0, 1), (0, -1)],
                   -1: [(1, 0), (-1, 0)]}

representBeamer = {1: "|", -1: "-"}

# Read a tuple:
# length, count = map(int, input().strip().split(" "))
# reverse lookup table
# dict(zip(?, count()))

T = int(input().strip())

for t in range(T):
    print("Case #{}: ".format(t + 1), end="")
    height, width = map(int, input().strip().split(" "))
    field = [list(input()) for i in range(height)]
    clauses = {}
    extraClauses = []
    beamers = []
    for y in range(height):
        for x in range(width):
            if field[y][x] == ".":
                clauses[(x, y)] = []
            elif field[y][x] in "-|":
                beamers.append((x, y))
    for number, origin in zip(count(1), beamers):
        for sign, directions in interpretBeamer.items():
            for direction in directions:
                pos = origin
                while True:
                    pos = vectoradd(pos, direction)
                    if pos[0] < 0 or pos[1] < 0 or pos[0] >= width or pos[1] >= height:
                        break
                    tile = field[pos[1]][pos[0]]
                    if tile == "#":
                        break
                    elif tile == '.':   
                        clauses[pos].append(sign*number)
                    elif tile in '|-':
                        extraClauses.append([-sign*number])
                        break
                    elif tile in '\\/':
                        direction = interpretSlash[tile][direction]
    extraClauses.extend(clauses.values())
    satSolution = pycosat.solve(extraClauses)
    if satSolution == 'UNSAT':
        print("IMPOSSIBLE")
        continue
    print("POSSIBLE")
    for i in satSolution:
        x, y = beamers[abs(i) - 1]
        field[y][x] = representBeamer[int(copysign(1, i))]
    for i in field:
        print(''.join(i))

