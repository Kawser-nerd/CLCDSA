import itertools

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

YES = 'POSSIBLE'
NO = 'IMPOSSIBLE'

for test in xrange(NUM_TESTS):
    R, C = map(int,IN.readline().split())
    grid = ['#' * (C+2)] * (R+2)
    for i in xrange(R):
        grid[i+1] = '#' + IN.readline().strip() + '#'
    answer = YES
    
    lasers = []
    blanks = set()
    for i in xrange(1, R+1):
        for j in xrange(1, C+1):
            if grid[i][j] in '-|':
                lasers.append((i, j))
            elif grid[i][j] == '.':
                blanks.add((i, j))
                
    free_lasers = []
    hor_saver = dict()
    ver_saver = dict()
    for laser in lasers:
        hor_illegal = ver_illegal = False
        hor_cover = set()
        ver_cover = set()
        
        x, y = laser
        while True:
            x += 1
            check = grid[x][y] 
            if check in '-|':
                hor_illegal = True
                break
            elif check == '#':
                break
            elif check == '.':
                hor_cover.add((x, y))
    
        x, y = laser
        while True:
            x -= 1
            check = grid[x][y] 
            if check in '-|':
                hor_illegal = True
                break
            elif check == '#':
                break
            elif check == '.':
                hor_cover.add((x, y))
    
        x, y = laser
        while True:
            y += 1
            check = grid[x][y] 
            if check in '-|':
                ver_illegal = True
                break
            elif check == '#':
                break
            elif check == '.':
                ver_cover.add((x, y))
        
        x, y = laser
        while True:
            y -= 1
            check = grid[x][y] 
            if check in '-|':
                ver_illegal = True
                break
            elif check == '#':
                break
            elif check == '.':
                ver_cover.add((x, y))
    
        x, y = laser
        
        if hor_illegal and ver_illegal:
            answer = NO
            break
        
        if hor_illegal:
            grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
            blanks -= ver_cover
        elif ver_illegal:
            grid[x] = grid[x][:y] + '|' + grid[x][y+1:]
            blanks -= hor_cover
        elif len(hor_cover) == 0:
            grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
            blanks -= ver_cover
        elif len(ver_cover) == 0:
            grid[x] = grid[x][:y] + '|' + grid[x][y+1:]
            blanks -= hor_cover
        else:
            grid[x] = grid[x][:y] + '*' + grid[x][y+1:]
            free_lasers.append((x, y, hor_cover, ver_cover))
            for i, j in hor_cover:
                hor_saver[(i, j)] = (x, y)
            for i, j in ver_cover:
                ver_saver[(i, j)] = (x, y)
    
    while answer == YES:
        if len(blanks) == 0:
            for x, y, hor_cover, ver_cover in free_lasers:
                grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
            break
        elif len(free_lasers) == 0:
            answer = NO
            break
        else:
            # print free_lasers
            for i, j in blanks:
                if (i, j) not in hor_saver and (i, j) not in ver_saver:
                    answer = NO
                    break
                elif (i, j) not in hor_saver:
                    x, y = ver_saver[(i, j)]
                    #print 'ver', x, y
                    for i, laser in enumerate(free_lasers):
                        xx, yy, hor_cover, ver_cover = laser
                        if x == xx and y == yy:
                            grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
                            blanks -= ver_cover
                            del free_lasers[i]
                            #print 'deleted!'
                            break
                    break
                elif (i, j) not in ver_saver:
                    x, y = hor_saver[(i, j)]
                    #print 'hor', x, y
                    for i, laser in enumerate(free_lasers):
                        xx, yy, hor_cover, ver_cover = laser
                        if x == xx and y == yy:
                            grid[x] = grid[x][:y] + '|' + grid[x][y+1:]
                            blanks -= hor_cover
                            del free_lasers[i]
                            #print 'deleted!'
                            break
                    break
                else:
                    continue
                break
            else:
                for x, y, hor_cover, ver_cover in free_lasers:
                    grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
                break
        '''elif len(free_lasers) > 20:
            answer = '@@@@@@@@@@@ HAND SOLVE @@@@@@@@@@@@@@'
        else:    
            answer = NO
            for iter in itertools.product([2, 3], repeat=len(free_lasers)):
                check = blanks.copy()
                for i, laser in enumerate(free_lasers):
                    check -= laser[iter[i]]
                if len(check) == 0:
                    answer = YES
                    for i, laser in enumerate(free_lasers):
                        x, y, hor_cover, ver_cover = laser
                        if i == 2:
                            grid[x] = grid[x][:y] + '|' + grid[x][y+1:]
                        else:
                            grid[x] = grid[x][:y] + '-' + grid[x][y+1:]
                    break'''
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer
    if answer != NO:
        for i in xrange(1, R+1):
            OUT.write(grid[i][1:-1] + '\n')
            print grid[i][1:-1]

IN.close()
OUT.close()
