#!/usr/bin/python3.2

import sys

if len(sys.argv) == 1:
    f = sys.stdin
    o = sys.stdout

if len(sys.argv) == 2:
    f = open(sys.argv[1], 'r')
    o = sys.stdout

if len(sys.argv) == 3:
    f = open(sys.argv[1], 'r')
    o = open(sys.argv[2], 'w')


def min_except(l, exc):
    l2 = sum(l, [])
    res = min([e for e in l2 if e != exc])
    return res

def print_lawn(lines):
    for l in lines:
        print(l)
    print()

def lawn(lines, sizex, sizey, case_id):
    valid = False

    min_height = min([min(l) for l in lines])
    max_height = max([max(l) for l in lines])


    while min_height != max_height:
        new_lawn = [list(l) for l in lines]

        next_height = min_except(lines, min_height)

        for x in range(sizex):
            l = [l[x] for l in lines]
            if all([e == min_height for e in l]):
                for y in range(sizey):
                    new_lawn[y][x] = next_height

        for y in range(sizey):
            l = lines[y]
            if all([e == min_height for e in l]):
                for x in range(sizex):
                    new_lawn[y][x] = next_height

        lines = new_lawn
        new_min_height = min([min(l) for l in lines])
        if new_min_height == min_height:
            return False

        min_height = new_min_height


    return True

case_id = 1
nb = int(f.readline().strip())
for t in range(nb):
    l = f.readline().strip()
    sizes = l.split(' ')
    sizey = int(sizes[0])
    sizex = int(sizes[1])

    lines = []
    for x in range(sizey):
        line = f.readline().strip()
        line = [int(l) for l in line.split(' ')]
        lines.append(line)

    valid = lawn(lines, sizex, sizey, case_id)
    if valid:
        print('Case #%d: YES' % case_id, file = o)
    else:
        print('Case #%d: NO' % case_id, file = o)
    case_id += 1


