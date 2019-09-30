import sys
import itertools

with open(sys.argv[1]) as f:
    lines = f.readlines()

T = int(lines[0],10)
for tt, l in enumerate(lines[1:]):
    K = int(l.split(" ")[0],10)
    C = int(l.split(" ")[1],10)
    S = int(l.split(" ")[2],10)
    
    # compute the number needed
    number_spots_influenced = C
    possible = (C * S >= K)
    if not possible:
        print ("Case #%d:" % (tt+1)), "IMPOSSIBLE"
        continue
    
    positions_to_check = range(K)
    positions = []
    while positions_to_check:
        x = positions_to_check[:C]
        positions_to_check = positions_to_check[C:]
        pos = 0
        for j,y in enumerate(x):
            pos *= K
            pos += y
        assert pos <= K**C
        positions.append(pos+1)
    
    print ("Case #%d:" % (tt+1)), " ".join(map(str,positions))

        

