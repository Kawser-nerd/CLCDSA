import os
import sys

problem_id = 'C'

sys.setrecursionlimit(10**9)
input_path = '%s.in' % problem_id
output_path = '%s.out' % problem_id


def read_line():
    line = ''
    while len(line) == 0:
        line = input_file.readline().strip()
    return line


def write_line(line):
    print line
    return output_file.write(line + os.linesep)


def solve():
    c, d, v = map(int, read_line().split(' '))
    ds = [0] * 200
    i = 0
    for num in map(int, read_line().split(' ')):
        ds[i] = num
        i += 1

    mmax = 0
    mcur = 0
    nc = 0
    ptr = 0
    while mmax < v:
        if mmax >= ds[ptr] - 1 and ptr < d:
            mcur = ds[ptr]
            ptr += 1
        else:
            mcur = mmax + 1
            nc += 1
        mmax += mcur * c
    return nc


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()