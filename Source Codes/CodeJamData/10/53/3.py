infile = open("C-small.in", "r")

T = int(infile.readline().strip())

for t in range(T):
    C = int(infile.readline().strip())
    corners = {}
    needs_moves = False
    for c in range(C):
        line = infile.readline().strip()
        P = int(line.split(' ')[0])
        V = int(line.split(' ')[1])
        #print V
        corners[P] = V
        if (V > 1):
            needs_moves = True

    total_moves = 0
    while needs_moves:
        #print sorted(corners.items())
        newcorners = {}
        needs_moves = False
        for key, value in sorted(corners.items()):
            if value == 1:
                if not newcorners.has_key(key):
                    newcorners[key] = 0
                newcorners[key] += 1
            elif value > 1:
                needs_moves = True
                moves = int(value/2)
                total_moves += moves

                if not newcorners.has_key(key-1):
                    newcorners[key-1] = 0
                if newcorners.has_key(key+1):
                    assert False
                newcorners[key-1] += moves
                newcorners[key+1] = moves
                if value > moves*2:
                    if not newcorners.has_key(key):
                        newcorners[key] = 0
                    newcorners[key] += 1
        corners = newcorners
    print "Case #" + str(t+1) + ": " + str(total_moves)
