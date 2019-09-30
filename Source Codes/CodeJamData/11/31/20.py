#!/usr/bin/python

"""
Square Tiles problem solution
(GCJ 2011, Round 1B)
Author: madrezaan
"""

import sys, math

# open input file
if len(sys.argv) == 2 and sys.argv[1] != '--help':
    in_file = open(sys.argv[1])
else:
    print "Usage: square_tiles.py <input file>"
    sys.exit(0)

# get number of cases
T = int(in_file.readline())

# begin prosessing cases
for cur_case in range(T):
    # get constants
    R, C = map(int, in_file.readline().split(" "))
    pic = []
    for i in range(R):
        pic.append(list(in_file.readline().strip()))
    # begin calculation
    for i in range(R-1):
        for j in range(C-1):
            if pic[i][j] == "#" and pic[i+1][j] == "#" and pic[i][j+1] == "#" and pic[i+1][j+1] == "#":
                pic[i][j] = "/"
                pic[i+1][j] = "\\"
                pic[i][j+1] = "\\"
                pic[i+1][j+1] = "/"
    is_possible = True
    for i in range(R):
        try:
            t = pic[i].index("#")
            is_possible = False
            break
        except:
            pass
    # output results
    print "Case #%d:" % (cur_case + 1, )
    if is_possible:
        for i in range(R):
            print "".join(pic[i])
    else:
        print "Impossible"
        
# close input file
in_file.close()

    
        
