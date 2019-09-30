sizes = set()

for a in range(1, 17):
    for b in range(1, 17):
        if a*b <= 16:
            sizes.add((a,b))

answers = {}
import itertools

def traverse(w,h,grid):
    d = {}
    e = {}
    
    for i in range(w*2+h*2):
        if i < w:
            pos = (0, i)
            dir = (1, 0)
        elif i < w+h:
            pos = (i-w, w-1)
            dir = (0, -1)
        elif i < w+h+w:
            pos = (h-1, w-1-(i-w-h))
            dir = (-1, 0)
        else:
            pos = ((w*2+h*2)-1-i, 0)
            dir = (0, 1)

        d[i] = (pos, dir)
        e[(pos[0]-dir[0], pos[1]-dir[1])] = i

    L = []

    for i in range(w*2+h*2):
        pos, dir = d[i]

        while 0 <= pos[0] < h and 0 <= pos[1] < w:
            if grid[pos[0]][pos[1]] == '/':
                dir = (-dir[1], -dir[0])
            else:
                dir = (dir[1], dir[0])

            pos = (pos[0]+dir[0], pos[1]+dir[1])

        L.append(e[pos])

    return L       

for w,h in sizes:
    print(w,h)
    n = w*h

    for x in itertools.product("/\\", repeat=n):
        grid = [x[i*w:(i+1)*w] for i in range(h)]
        R = traverse(w,h,grid)
        answers[(tuple(R),w,h)] = grid

#x = input("Press enter to continue:")
# C-small-attempt0

with open("C-small-attempt0.in") as infile:
    with open("c.out", "w") as outfile:
        cases = int(next(infile))

        for case in range(1, cases+1):
            h, w = map(int, next(infile).split())
            courtiers = list(map(int, next(infile).split()))

            L = [0]*(2*w+2*h)
            
            while courtiers:
                x = courtiers.pop()-1
                y = courtiers.pop()-1

                L[x] = y
                L[y] = x

            print("Case #{}:".format(case), file=outfile)

            key = (tuple(L),w,h)

            if key in answers:
                result = answers[key]

                for line in result:
                    print(*line, file=outfile, sep='')

            else:
                print("IMPOSSIBLE", file=outfile)

            
