import os
import sys
from collections import defaultdict

problem_id = 'B'

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


def compute_shifts(pattern):
    shifts = [None] * (len(pattern) + 1)
    shift = 1
    for pos in range(len(pattern) + 1):
        while shift < pos and pattern[pos-1] != pattern[pos-shift-1]:
            shift += shifts[pos-shift-1]
        shifts[pos] = shift
    return shifts


def solve():
    k, l, s = map(int, read_line().split(' '))
    keyboard = read_line()
    target = read_line()
    letter = defaultdict(int)
    for key in keyboard:
        letter[key] += 1
    numerator = 1
    for char in target:
        numerator *= letter[char]
    denominator = k ** l + 0.0
    if numerator == 0:
        return 0.0
    shifts = compute_shifts(target)
    total_banana = 1.0 + (s - l) / shifts[-1]
    return total_banana - (s - l + 1) * numerator / denominator


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %f" % (case_id, solve()))
input_file.close()
output_file.close()