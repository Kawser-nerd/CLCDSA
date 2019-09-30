# Block diag

grids = [[[1]], [[1,0],[0,1]], [[1,1],[1,1]], [[1,0,0],[0,1,0],[0,0,1]], [[1,1,0],[1,1,0],[0,0,1]], [[1,1,1],[1,1,1],[1,1,1]],
         [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]], [[1,1,1,0],[1,1,1,0],[1,1,1,0],[0,0,0,1]],
         [[1,1,0,0],[1,1,0,0],[0,0,1,0],[0,0,0,1]], [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]]

grids = {tuple(map(tuple, g)) for g in grids}

new_grids = set()

import itertools

for grid in grids:
    n = len(grid)

    for x in itertools.permutations(range(n)):
        for y in itertools.permutations(range(n)):
            g = [grid[a] for a in x]
            G = []

            for r in g:
                G.append([r[b] for b in y])
            new_grids.add(tuple(map(tuple, G)))
        

with open("D-small-attempt1.in") as infile:
    with open("d.out", "w") as outfile:
        cases = int(next(infile))

        for case in range(1, cases+1):
            n = int(next(infile))
            L = []

            for _ in range(n):
                L.append(list(map(int, next(infile).rstrip())))

            best = None

            for x in new_grids:
                if len(x) == n:
                    valid = True
                    total = 0
                    
                    for i in range(n):
                        for j in range(n):
                            if L[i][j] < x[i][j]:
                                total += 1
                            elif L[i][j] > x[i][j]:
                                valid = False
                                break

                        if valid == False:
                            break

                    if valid and (best is None or total < best):
                        best = total

            print("Case #{}: {}".format(case, best), file=outfile)
