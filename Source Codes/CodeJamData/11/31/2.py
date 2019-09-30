T = int(raw_input())

for t in range(T):
    R,C = map(int, raw_input().split(' '))
    grid = ""
    for r in range(R):
        grid += raw_input()
    grid = list(grid)

    try:
        while True:
            s = grid.index(r"#")
            if (s%C) != C-1 and s//C != R-1 and grid[s+1]+grid[s+C]+grid[s+C+1] == '###':
                grid[s] = '/'
                grid[s+1] = "\\"
                grid[s+C] = '\\'
                grid[s+C+1] = '/'
            else:
                break
    except ValueError:
        pass

    print "Case #%d:" % (t+1)
    try:
        grid.index('#')
        print "Impossible"
    except ValueError:
        for r in range(R):
            print ''.join(grid[r*C:(r+1)*C])
