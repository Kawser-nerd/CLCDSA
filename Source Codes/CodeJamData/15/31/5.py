import os
import sys
from collections import defaultdict

problem_id = 'A'

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
    r, c, w = map(int, read_line().split(' '))
    nc = (c / w) * r + (w - 1)
    if c % w:
        nc += 1
    return '%s' % nc


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()