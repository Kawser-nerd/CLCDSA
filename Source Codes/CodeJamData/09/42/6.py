import math
import collections
from heapq import heappush, heappop

def successors(score, digs, state):
    # Return child NODES
    successors = set()
    (r, c), cleared = state
    assert r < rows - 1   # better be at the bottom
    if c > 0:
        # can we move to the left???
        if clear(r, c - 1, cleared):
            fallen = fall_down(r, c - 1, cleared)
            if fallen is not None:
                cs = (fallen, cleared)
                successors.add(((score, digs), cs))
            # Can I drill to da left?
            if not clear(r + 1, c - 1, cleared):
                # yaaaaa diglett go
                ncleared = cleared | frozenset([(r + 1, c - 1)])
                cs = ((r, c), ncleared)
                ranker = (heuristic(cs) + digs + 1, digs + 1)
                successors.add((ranker, cs))
    if c < cols - 1:
        # can we move to the left???
        if clear(r, c + 1, cleared):
            fallen = fall_down(r, c + 1, cleared)
            if fallen is not None:
                cs = (fallen, cleared)
                successors.add(((score, digs), cs))
            # Can I drill to da left?
            if not clear(r + 1, c + 1, cleared):
                # yaaaaa diglett go
                ncleared = cleared | frozenset([(r + 1, c + 1)])
                cs = ((r, c), ncleared)
                ranker = (heuristic(cs) + digs + 1, digs + 1)
                successors.add((ranker, cs))
    #print 'S:', successors
    return successors

def clear(r, c, cleared):
    return grid[(r, c)] or (r, c) in cleared

def fall_down(r, c, cleared):
    bad = False
    newpos = (r, c)
    for r_ in range(r + 1, rows):
        if clear(r_, c, cleared):
            if r_ - r > fall:
                bad = True
                break
            newpos = (r_, c)
        else: break
    return newpos if not bad else None

def swap(state, i, j):
    copy = list(state)
    copy[i], copy[j] = state[j], state[i]
    return tuple(copy)

def is_goal(state):
    (r, c), cleared = state
    return r == rows - 1

def solve_search(root):
    # States are ((r, c), cleared) tuples.
    # Nodes are (digs, state) tuples.
    expanded = set()
    queue = [root]
    while queue:
        (score, digs), current = heappop(queue)
        if is_goal(current):
            return digs
        if current not in expanded:
            expanded.add(current)
            for child_node in successors(score, digs, current):
                (cscore, cdigs), child = child_node
                if child not in expanded:
                    heappush(queue, child_node)
    return None

def heuristic(state):
    return 0
    # How close to bottom?
    (r, c), cleared = state
    tobottom = rows - r - 1
    lollerskates = tobottom
    for i in range(1, tobottom + 1):
        for c_ in range(cols):
            if grid[(rows - i, c_)] is True:
                lollerskates -= 1
                break
    return lollerskates

def root_node():
    state = ((0, 0), frozenset())
    return ((heuristic(state), 0), state)

input_file  = 'B-small-attempt1.in'
output_file = 'B-small-attempt1.out.txt'
#input_file = 'digging.txt'
prob, out = open(input_file), open(output_file, 'w')
cases = int(prob.next().strip())

grid, rows, cols, fall = {}, 0, 0, 0

for i in range(1, cases + 1):
    rows, cols, fall = [int(s) for s in prob.next().strip().split()]
    # Read in the grid.
    grid = {}
    for r in range(rows):
        row_input = prob.next().strip()
        for c in range(cols):
            grid[(r, c)] = True if row_input[c] == '.' else False
    solution = solve_search(root_node())
    if solution is not None:
        print 'Case #%d: Yes %d' % (i, solution)
        out.write('Case #%d: Yes %d\n' % (i, solution))
    else:
        print 'Case #%d: No' % (i,)
        out.write('Case #%d: No\n' % (i,))
    
prob.close()
out.close()
