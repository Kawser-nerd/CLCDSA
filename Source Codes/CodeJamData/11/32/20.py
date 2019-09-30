#!/usr/bin/python

"""
Space Emergency problem solution
(GCJ 2011, Round 1B)
Author: madrezaan
"""

import sys, math

# open input file
if len(sys.argv) == 2 and sys.argv[1] != '--help':
    in_file = open(sys.argv[1])
else:
    print "Usage: space_emergency.py <input file>"
    sys.exit(0)

# get number of cases
T = int(in_file.readline())

# begin prosessing cases
for cur_case in range(T):
    # get constants
    distances = map(int, in_file.readline().split(" "))
    L, t, N, C = distances[0], distances[1], distances[2], distances[3]
    distances = distances[4:]
    time = 0
    savings = []
    # begin calculation
    for i in range(N):
        if t <= time:
            savings.append(distances[i % C])
        elif t <= time + distances[i % C] * 2:
            savings.append(distances[i % C] - float(t - time) / 2)
        else:
            savings.append(0)
        time += distances[i % C] * 2
    savings.sort()
    savings.reverse()
    time -= sum(savings[:L])
    # output results
    print "Case #%d: %s" % (cur_case + 1, int(time))

# close input file
in_file.close()

    
        
