import fileinput

__author__ = 'psmit'

IND = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def next_locs(loc, W, prev_loc=None):
    if prev_loc is None:
        if (loc[0] > 0):
            yield (loc[0]-1, loc[1])
        yield (loc[0], loc[1]+1)
        if (loc[0] < W-1):
            yield (loc[0]+1, loc[1])
        if (loc[1] > 0):
            yield (loc[0], loc[1]-1)
    else:
        dir = (prev_loc[0] - loc[0], prev_loc[1] - loc[1] )

        for _ in range(4):
            dir = (dir[1], -1 * dir[0])

            new_loc = (loc[0] + dir[0], loc[1] + dir[1])
            if 0 <= new_loc[0] < W and 0 <= new_loc[1]:
                yield new_loc
            # yield (loc[0] + dir[0], loc[1] + dir[1])


def print_grid(grid, W, H):
    for y in range(H-1, -1, -1):
        print("".join('.' if grid[x][y] else 'x' for x in range(W)))

def print_grid2(grid2, W, H):
    for y in range(H-1, -1, -1):
        print("".join(grid2[x][y] for x in range(W)))

def main():

    inp = fileinput.input()

    T = int(inp.readline())

    for t in range(1,T+1):
        buildings = []
        W, H, B = (int(x) for x in inp.readline().split())
        for _ in range(B):
            buildings.append([int(x) for x in inp.readline().strip().split()])

        grid = []
        grid2 = []
        for _ in range(W):
            grid.append([True] * H)
            grid2.append(["."] * H)

        for building in buildings:
            for x in range(building[0], building[2] + 1):
                for y in range(building[1], building[3] + 1):
                    grid[x][y] = False
                    grid2[x][y] = "x"


        # print_grid(grid, W, H)
            # for x in range(W):
            #     print

        num_traces = 0
        for start_x in range(W):

            s_loc = (start_x,0)
            if not grid[s_loc[0]][s_loc[1]]:
                continue
            else:
                grid[s_loc[0]][s_loc[1]] = False
                # grid2[s_loc[0]][s_loc[1]] = IND[num_traces]

            # print_grid2(grid2, W, H)
            loc_stack = [s_loc]


            while True:
                # print_grid2(grid2, W, H)
                found = False
                for nloc in next_locs(loc_stack[-1], W, loc_stack[-2] if len(
                        loc_stack) > 1 else None):
                    if grid[nloc[0]][nloc[1]] == True:
                        loc_stack.append(nloc)
                        found = True
                        grid[nloc[0]][nloc[1]] = False
                        # grid2[nloc[0]][nloc[1]] = IND[num_traces]
                        break

                if found:
                    if loc_stack[-1][1] == H-1:
                        num_traces += 1
                        break


                if not found:
                    # try to trace back
                    if len(loc_stack) > 1:
                        loc_stack = loc_stack[:-1]
                    else:
                        break

        print("Case #{}: {}".format(t, num_traces))



main()