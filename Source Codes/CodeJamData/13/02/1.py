import sys

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    N, M = map(int, f.readline().strip().split())
    grass_lengths = []
    for nn in range(N):
        grass_lengths.append(map(int, f.readline().strip().split())) # Read in all grass heights

    x_max = [0] * M
    y_max = [0] * N
    for xx in range(M):
        for yy in range(N):
            height = grass_lengths[yy][xx]
            x_max[xx] = max(x_max[xx], height)  # Update the max required height for column x
            y_max[yy] = max(y_max[yy], height)  # Update the max required height for row y

    impossible = False
    for xx in range(M):
        for yy in range(N):
            height = grass_lengths[yy][xx]
            if (x_max[xx] > height and y_max[yy] > height): # Can we cut this row down to this level?
                impossible = True

    print "Case #%d:" % (t + 1), "NO" if impossible else "YES"
