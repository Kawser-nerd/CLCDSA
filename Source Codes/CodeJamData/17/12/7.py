#! /usr/bin/python

import sys
from fractions import Fraction

def read_case(f):
    n, p = read_space_line(f, int)
    recipe = read_space_line(f, int)
    assert len(recipe) == n
    packets = []
    for _ in range(n):
        packets.append(read_space_line(f, int))
    return n, p, recipe, packets

def solve(case):
    n, p, recipe, packets = case
    sorted_packets = []
    for i, packet in enumerate(packets):
        sorted_packet = list(reversed(sorted(packet)))
        sorted_packet = [Fraction(packet) / recipe[i] for packet in
                         sorted_packet]
        sorted_packets.append(sorted_packet)

    num_kits = 0
    # The following will eliminate at least one packet each time, and will have
    # runtime linear in the number of ingredients, so N X P <= 1000...
    while all(packet for packet in sorted_packets):
        # No heaps YOLO SWAG
        greatest, idx = max((packet[0], i) for i, packet in
                             enumerate(sorted_packets))
        least = min(packet[0] for packet in sorted_packets)
        mean = (greatest + least) / 2
        # Find both the ceiling and floor of this number of recipes and see if
        # either includes both greatest and least. If not, remove the greatest.
        # If so, remove all and incr counter.
        lower = Fraction(int(mean))
        upper = lower + 1
        winner = False
        for servings in (lower, upper):
            if (servings * Fraction(9, 10) <= least and servings * Fraction(11,
                                                                            10)
                >= greatest):
                winner = True
                break

        if winner:
            sorted_packets = [packet[1:] for packet in sorted_packets]
            num_kits += 1
        else:
            sorted_packets[idx] = sorted_packets[idx][1:]


    return num_kits

# Edit over here --------

def read_space_line(f, constr):
    # Reads a space-delimited line with constructor.
    line = f.readline().strip().split(' ')
    return tuple(int(x) for x in line)

def read_line(f, constr):
    return constr(f.readline().strip())

def input_iterator(in_fn):
    with open(in_fn) as f:
        num_cases = read_line(f, int)
        for i in range(num_cases):
            yield read_case(f)

def write_output(f, case_n, sol_str):
    f.write("Case #%d: %s\n" % (case_n, sol_str))

def main():
    in_fn = sys.argv[1] 
    out_fn = sys.argv[2]
    
    with open(out_fn, 'w') as out_f:
        for i, case in enumerate(input_iterator(in_fn)):
            sol_str = solve(case)
            write_output(out_f, i+1, sol_str)

if __name__ == "__main__":
    main()


