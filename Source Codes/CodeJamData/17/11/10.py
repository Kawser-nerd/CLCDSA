#! /usr/bin/python

import sys

def read_case(f):
    r, c = read_space_line(f, int)
    grid = []
    for _ in range(r):
        line = read_line(f, str)
        line = list(line)
        grid.append(line)
    return r, c, grid

def get_val(grid, pos):
    x, y = pos
    return grid[x][y]

def solve(case):
    children = []
    child_to_coord = {}
    r, c, grid = case
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell != '?':
                children.append(cell)
                child_to_coord[cell] = (i, j)

    # Start filling in the whole grid.
    first = children[0]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            grid[i][j] = first

    # Do the rest.
    for child in children[1:]:
        child_pos = child_to_coord[child]
        parent_pos = child_to_coord[get_val(grid, child_pos)]
        parent_val = get_val(grid, child_pos)
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == parent_val:
                    # If we're "closer" to the child, change the value.
                    if child_pos[0] != parent_pos[0]:
                        dist_c = abs(i - child_pos[0])
                        dist_p = abs(i - parent_pos[0])
                    else:
                        dist_c = abs(j - child_pos[1])
                        dist_p = abs(j - parent_pos[1])
                    if dist_c < dist_p:
                        grid[i][j] = child

    # transform to string
    grid = [''.join(line) for line in grid]

    return '\n' + '\n'.join(grid)

# Edit over here --------

def read_space_line(f, constr):
    # Reads a space-delimited line with constructor.
    line = f.readline().strip().split(' ')
    return tuple(int(x) for x in line)

def read_line(f, constr):
    return constr(f.readline().strip())

def input_iterator(in_fn):
    with open(in_fn) as f:
        num_cases = read_line(f, int)
        for i in range(num_cases):
            yield read_case(f)

def write_output(f, case_n, sol_str):
    f.write("Case #%d: %s\n" % (case_n, sol_str))

def main():
    in_fn = sys.argv[1] 
    out_fn = sys.argv[2]
    
    with open(out_fn, 'w') as out_f:
        for i, case in enumerate(input_iterator(in_fn)):
            sol_str = solve(case)
            write_output(out_f, i+1, sol_str)

if __name__ == "__main__":
    main()


