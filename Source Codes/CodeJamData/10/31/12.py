# MISC
read_int = lambda:int(raw_input().strip())
read_ints = lambda:[int(x) for x in raw_input().split()]
count_to = lambda n:xrange(1,n+1)

# GENERAL GRID TOOLS
def read_grid(rows, columns, parse_cell=None):
    if parse_cell is None:
        parse_cell = lambda x:x
    grid = {}
    for r in count_to(rows):
        rowstring = raw_input()
        for c in count_to(columns):
            grid[r,c] = parse_cell(rowstring[c-1])
    return grid

def print_grid(rows, columns, grid, f=None):
    if f is None:
        f = lambda x:x
    for r in count_to(rows):
        print "".join(f(grid[r,c]) for c in count_to(columns))

def create_grid(rows, columns, f):
    return dict(
        ((r,c), f(r,c))
        for r in count_to(rows)
        for c in count_to(columns))

# GENERAL SOLVE LOOP
def solve_all(solve):
    num_cases = read_int()
    for i in count_to(num_cases):
         print "Case #{0}:".format(i),
         solve()

# SOLUTION

def wires_cross(w1, w2):
    wires = [w1, w2]
    wires.sort()
    return wires[0][1]>wires[1][1]

def solve_case():
    num_wires = read_int()
    wires = [read_ints() for i in xrange(num_wires)]
    count = 0
    for a in wires:
        for b in wires:
            if wires_cross(a,b):
                count += 1
    print count//2

solve_all(solve_case)
