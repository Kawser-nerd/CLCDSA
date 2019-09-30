import itertools
import random

def genrandom(h, w):
    g = [[0]*w for _ in range(h)]
    for i in range(1, h-1):
        for j in range(1, w-1):
            if random.randint(0,1):
                g[i][j] = 1
    return g

def display(g):
    for i in range(len(g)):
        print(''.join('#' if b else '.' for b in g[i]))

h,w = [int(s) for s in input().split()]
g = [[0]*w for _ in range(h)]

for i in range(h):
    s = input()
    for (j,c) in enumerate(s):
        if c == '#':
            g[i][j] = 1

red = [list(g[i]) for i in range(h)]
blue = [list(g[i]) for i in range(h)]

for i in range(h):
    red[i][-1] = 1
    blue[i][0] = 1
    if i % 2 == 0:
        for j in range(1,w-1):
            red[i][j] = 1
    else:
        for j in range(1,w-1):
            blue[i][j] = 1

display(red)
print()
display(blue)
#purp = [[red[i][j]&blue[i][j] for j in range(w)] for i in range(h)]
#assert(purp == g)