#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

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
    N, W, L = input_ints()
    r = array(input_floats())    
    x = zeros(N)
    y = zeros(N) + 1

    flip = (W < L)
    if flip:
        L, W = W, L

    ranks = argsort(-r)

    track_x = -r[ranks[0]]
    track_y = r[ranks[0]]
    current_y = 0

#    import pdb; pdb.set_trace()

    # go from largest on down
    for i in ranks:
        if track_x + r[i] <= W:
            # fits in same row
            x[i] = track_x + r[i]
            track_x = track_x + 2 * r[i]

            y[i] = current_y
        else:
            # must start new row
            x[i] = 0
            track_x = r[i]

            current_y = track_y + r[i]
            if current_y > L:
                raise "bad news"
            track_y = track_y + 2*r[i]
            y[i] = current_y

    if flip:
        x, y = y, x

    result = zeros(2 * N)
    result[::2] = x
    result[1::2] = y
    
    return format_sequence(result)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()


