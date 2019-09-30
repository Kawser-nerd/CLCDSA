import pdb
import sys
import re
import time
from collections import namedtuple
from itertools import product
from copy import copy, deepcopy

taskname = 'C'
input = None

def readstr():
    return next(input).strip()

def readintlist():
    lst = map(int, readstr().split())
    return lst

def readint():
    lst = readintlist()
    assert len(lst) == 1
    return lst[0]

def split_room(room, wall):
    for i, v in enumerate(room):
        if v in wall:
            wall.remove(v)
            return room[:i + 1], room[i:]
    assert False


def solvecase():
    v_cnt, w_cnt = readintlist()
    def read_lst():
        lst = readintlist()
        return [c - 1 for c in lst]
    walls = zip(read_lst(), read_lst())
    assert len(walls) == w_cnt
    rooms = [set(xrange(v_cnt))]
    def find_room_idx(v):
        return set(i for i, room in enumerate(rooms) if v in room)
    for w1, w2 in walls:
        i1 = find_room_idx(w1)
        i2 = find_room_idx(w2)
        intersection = i1 & i2
        assert len(intersection) == 1
        i = intersection.pop()
        room = sorted(rooms[i])
        del rooms[i]
        wall = [w1, w2]
        p1, p2 = split_room(room, wall)
        p2, p3 = split_room(p2, wall)
        rooms.append(set(p2))
        rooms.append(set(p1 + p3))
    print rooms
    min_len = min(len(room) for room in rooms)
    for colors in xrange(min_len, 0, -1): 
        for coloring in product(*[range(colors) for _ in range(v_cnt - 1)]):
            coloring = coloring + (0,) # a little speedup
            for room in rooms:
                c_set = set(coloring[i] for i in room)
                if len(c_set) != colors:
                    break
            else:
                return '{}\n{}'.format(colors, ' '.join(str(c + 1) for c in coloring))

def solve(suffix):
    global input
    tstart = time.clock()
    input = open(taskname + '-' + suffix + '.in', 'r')
    output = open(taskname + '-' + suffix + '.out', 'w')
    casecount = readint()
    
    for case in range(1, casecount + 1):
        s = solvecase()
        s = "Case #%d: %s" % (case, str(s)) 
        print >>output, s
        print s 
        
    input.close()
    output.close()
    print '%s solved in %.3f' % (suffix, time.clock() - tstart)
            
if __name__ == '__main__':
    solve('small')
    solve('large')
