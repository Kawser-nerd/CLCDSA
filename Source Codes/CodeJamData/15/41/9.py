#!/usr/bin/env python3

# Google Code Jam Round 2 2015
# Problem A. Pegman
# Solution in Python
# By Smithers

def scanup(grid, y0, x):
    for y in range(y0-1, -1, -1):
        if grid[y][x] != '.':
            return True
    return False

def scanright(grid, y, x0):
    for x in range(x0+1, len(grid[0]), +1):
        if grid[y][x] != '.':
            return True
    return False

def scandown(grid, y0, x):
    for y in range(y0+1, len(grid), +1):
        if grid[y][x] != '.':
            return True
    return False

def scanleft(grid, y, x0):
    for x in range(x0-1, -1, -1):
        if grid[y][x] != '.':
            return True
    return False

def scanany(grid, y, x):
    return scanup(grid, y, x) or scanright(grid, y, x) or scandown(grid, y, x) or scanleft(grid, y, x)

def solve(R, C, grid):
    result = 0
    for y in range(R):
        for x in range(C):
            c = grid[y][x]
            if c == '^':
                if not scanup(grid, y, x):
                    if not scanany(grid, y, x):
                        return 'IMPOSSIBLE'
                    result += 1
            elif c == '>':
                if not scanright(grid, y, x):
                    if not scanany(grid, y, x):
                        return 'IMPOSSIBLE'
                    result += 1
            elif c == 'v':
                if not scandown(grid, y, x):
                    if not scanany(grid, y, x):
                        return 'IMPOSSIBLE'
                    result += 1
            elif c == '<':
                if not scanleft(grid, y, x):
                    if not scanany(grid, y, x):
                        return 'IMPOSSIBLE'
                    result += 1
    return result

for x in range(1, int(input()) + 1):
    R, C = map(int, input().split())
    grid = [input() for i in range(R)]
    
    print('Case #' + str(x) + ':', solve(R, C, grid))
