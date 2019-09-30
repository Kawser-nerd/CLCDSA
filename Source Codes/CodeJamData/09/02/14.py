import sys

def get_neighboring_cell(cell, direction):
    assert direction in (0, 1, 2, 3)
    if direction == 0:
        return (cell[0]-1, cell[1])
    elif direction == 1:
        return (cell[0], cell[1]-1)
    elif direction == 2:
        return (cell[0], cell[1]+1)
    elif direction == 3:
        return (cell[0]+1, cell[1])

def get_neighbor_tuple(cell, map_heights, direction):
    neighbor_cell = get_neighboring_cell(cell, direction)
    return (map_heights[neighbor_cell[0]][neighbor_cell[1]], direction,
            neighbor_cell)

def rec_add_cell_sink(sinks_by_cell, cell, map_heights, height, width):
    if cell in sinks_by_cell:
        return
    
    neighbors = []
    if cell[0] > 0: # there is a north neighbor
        neighbors.append(get_neighbor_tuple(cell, map_heights, 0))
    if cell[1] > 0: # there is a west neighbor
        neighbors.append(get_neighbor_tuple(cell, map_heights, 1))
    if cell[1] < width - 1: # there is an east neighbor
        neighbors.append(get_neighbor_tuple(cell, map_heights, 2))
    if cell[0] < height - 1: # there is a south neighbor
        neighbors.append(get_neighbor_tuple(cell, map_heights, 3))

    neighbors.sort()

    if len(neighbors) > 0 and neighbors[0][0] < map_heights[cell[0]][cell[1]]:
        rec_add_cell_sink(sinks_by_cell, neighbors[0][2], map_heights, height,
                          width)
        sinks_by_cell[cell] = sinks_by_cell[neighbors[0][2]]
    else:
        sinks_by_cell[cell] = cell

def read_map_heights(in_fp, height, width):
    map_heights = []
    for i in range(height):
        map_heights.append(map(int, in_fp.readline().split()))
        assert len(map_heights[-1]) == width
    return map_heights

def get_sinks_by_cell(map_heights, height, width):
    sinks_by_cell = {}
    for y in range(height):
        for x in range(width):
            rec_add_cell_sink(sinks_by_cell, (y, x), map_heights, height, width)
    return sinks_by_cell

def get_labelled_cells(sinks_by_cell, height, width):
    index = -1
    labels_by_sink = {}
    labelled_cells = []
    
    for y in range(height):
        labelled_cells.append([])
        for x in range(width):
            sink_cell = sinks_by_cell[(y, x)]
            if sink_cell not in labels_by_sink:
                index += 1
                assert 0<= index < 26
                labels_by_sink[sink_cell] = chr(ord('a') + index)
            labelled_cells[-1].append(labels_by_sink[sink_cell])
    
    return labelled_cells

def solve_case(in_fp):
    height, width = map(int, in_fp.readline().split())
    map_heights = read_map_heights(in_fp, height, width)
    sinks_by_cell = get_sinks_by_cell(map_heights, height, width)
    labelled_cells = get_labelled_cells(sinks_by_cell, height, width)
    return '\n' +\
           '\n'.join(' '.join(lc for lc in row) for row in labelled_cells)

def main(argv):
    sys.setrecursionlimit(100000)
    
    in_fp = open(argv[1], 'rb')
    out_fp = open(argv[2], 'wb')

    num_cases = int(in_fp.readline())
    for i in range(num_cases):
        solution = solve_case(in_fp)
        out_fp.write('Case #%d: %s\n' % (i+1, solution))
    
    in_fp.close()
    out_fp.close()

if __name__ == '__main__':
    main(sys.argv)
