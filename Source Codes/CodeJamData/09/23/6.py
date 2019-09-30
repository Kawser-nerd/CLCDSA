# A*. Enough said.
from operator import add, sub
from heapq import heappush, heappop

def successors(state, grid):
    # Return a (child-state, action) tuple, where action is the value
    # of the new grid cell as a string.
    (r, c), val, op = state
    neighbors = [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]
    neighbors = [(r, c) for r, c in neighbors if in_grid(r, c, grid)]
    successors = []
    for nr, nc in neighbors:
        if type(grid[nr][nc]) is int:
            child = ((nr, nc), op(val, grid[nr][nc]), None)
        else:
            child = ((nr, nc), val, add if grid[nr][nc] is '+' else sub)
        successors.append((child, str(grid[nr][nc])))
    return successors

def is_goal(state, target):
    (r, c), val, op = state
    return val == target

def root_nodes(grid):
    roots = []
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            value = grid[r][c]
            if type(value) is int:
                state = ((r, c), value, None)
                expr = str(value)
                node = ((len(expr), expr), state)
                heappush(roots, node)
    return roots

def solve_search(grid, target):
    # States are ((r, c), value, operator) tuples.
    # Nodes are ((exprlen, expr), state) tuples.
    expanded = set()
    queue = root_nodes(grid)
    while queue:
        (exprlen, expression), current = heappop(queue)
        if is_goal(current, target):
            return expression
        if current not in expanded:
            expanded.add(current)
            for child, action in successors(current, grid):
                if child not in expanded:
                    child_expr = expression + action
                    child_node = ((len(child_expr), child_expr), child)
                    heappush(queue, child_node)
    print 'No solution found. Uh oh!'
    return None

def in_grid(r, c, grid):
    return 0 <= r < len(grid) and 0 <= c < len(grid[0])

def parse_grid(input, size):
    grid = []
    for i in range(size):
        row = []
        row, row_input = row, input.next().strip()
        for c in row_input:
            row.append(c if c == '+' or c == '-' else int(c))
        grid.append(row)
    return grid

with open('C-small-attempt0.in') as f:
    o = open('squareout.txt', 'w')
    cases = int(f.next())
    for i in range(1, cases + 1):
        print('Case #%d:' % i)
        o.write('Case #%d:\n' % i)
        grid_size, query_count = [int(s) for s in f.next().split()]
        grid = parse_grid(f, grid_size)
        queries = [int(q) for q in f.next().split()]
        for query in queries:
            soln = solve_search(grid, query)
            print soln
            o.write(soln + '\n')
    o.close()
