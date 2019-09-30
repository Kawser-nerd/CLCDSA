#!/usr/bin/env python3

def spread(row, empty_in, empty_out):
    for v in row:
        if v != empty_in:
            row[0] = v
            break
    else:
        return empty_out
    prev = row[0]
    for i in range(1, len(row)):
        if row[i] == empty_in:
            row[i] = prev
        else:
            prev = row[i]
    return row

def solve(grid):
    grid = list(map(lambda row: spread(row, '?', []), grid))
    grid = spread(grid, [], None)
    return grid

def main():
    t = int(input())
    for ti in range(t):
        r, c = list(map(int, input().split(" ")))
        grid = [list(input()) for _ in range(r)]
        grid = solve(grid)
        print("Case #{}:".format(ti+1))
        for row in grid:
            print(''.join(row))

if __name__ == '__main__':
    main()
