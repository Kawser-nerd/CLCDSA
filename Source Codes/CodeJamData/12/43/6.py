#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

MAX_HEIGHT = 1000000000
#MAX_HEIGHT = 100

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

def format_sequence(s, formatter='%s'):
    return " ".join(map(lambda x: formatter % (x,), s))


def solve_one():
    """ XXX the real code comes here """
    N = input_ints()[0]
    hi = array(input_ints()) - 1
    
    for i in range(len(hi)):
        for j in range(i + 1, hi[i]):
            if hi[j] > hi[i]:
                return "Impossible"

    result = zeros(len(hi) + 1, dtype=int)

    bounds = ones_like(result) * MAX_HEIGHT

    for j in range(len(result)-1, -1, -1):
        if j not in hi:
            continue
        result[j] = int(bounds[j] - 1)

        if j < len(hi):
            for m in range(hi[j] + 1, len(result)):
                slope = (result[m] - result[hi[j]]) / float(m - hi[j])
                target_height = result[hi[j]] - slope * (hi[j] - j)
                if target_height < result[j]:
#                    print "height adjustment", j, hi[j], result[j], target_height
                    result[j] = min(result[j], int(target_height - 1))

        for i in range(j):
            if hi[i] != j:
                continue
            # worst case: i will be height 0
            slope = result[j] / float(j - i)
            for k in range(i + 1, j):
                bounds[k] = min(bounds[k], slope * float(k - i))
#                print "set bound on", i, "to", j, "slope", slope, "for", k, "to", bounds[k]

#     for i in range(len(hi)):
#         target_slope = (result[hi[i]] - result[i]) / float(hi[i] - i) 
#         for j in range(i + 1, N):
#             if (result[j] - result[i]) / float(j - i) > target_slope:
# #                print i, '-->', hi[i], ' vs ', j
#                 raise "this is not going to work"

    return format_sequence(result)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()


