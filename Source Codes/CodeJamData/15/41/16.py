# python 3.4 !!

#from functools import lru_cache
#@lru_cache(maxsize = None)

num_trials = int(input())

def try_all_directions(grid, R, C, i, j):
    for dir in ['^', 'v', '<', '>']:
        success = try_direction(grid, R, C, i, j, dir)
        if (success):
            return True
    return False

def try_direction(grid, R, C, i, j, dir):
    diri = 0
    dirj = 0
    if dir == '^':
        diri = -1
        dirj = 0
    elif dir == 'v':
        diri = 1
        dirj = 0
    elif dir == '<':
        diri = 0
        dirj = -1
    else:
        diri = 0
        dirj = 1

    while (True):
        i += diri
        j += dirj
        if i < 0 or i >= R or j < 0 or j >= C:
            return False # fell!
        if grid[i][j] != '.':
            return True # made it to another arrow

    print("error???")
    return False # shouldn't get here?


def compute():
    R, C = map(int, input().split())
    grid = []
    for i in range(0, R):
        grid.append(list(input()))
    #print(grid)

    count = 0
    for i in range(0, R):
        for j in range(0, C):
            if grid[i][j] != '.':
                #print(i, j)
                if (not try_direction(grid, R, C, i, j, grid[i][j])):
                    count += 1
                    success = try_all_directions(grid, R, C, i, j)
                    if (not success):
                        return "IMPOSSIBLE"

    return count

for i in range (0, num_trials):
    print("Case #" + str(i+1) + ": " + str(compute()))
