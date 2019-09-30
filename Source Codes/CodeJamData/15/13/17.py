#! /usr/bin/python3

from itertools import chain, combinations

def load_file(chemin):
    def parse_input(f): # TODO
        n = int(f.readline())
        forest = []
        for i in range(n):
            [x,y] = [int(n) for n in f.readline().split()]
            forest += [(x,y)]
        return forest

    from os.path import isfile
    with open(chemin, 'r') as file:
        for _ in range(int(file.readline())):
            yield parse_input(file)
        file.close()

# http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
def convex_hull(points):
    points = sorted(set(points))
    if len(points) <= 1:
        return points
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)
    return lower[:-1] + upper[:-1]

def powerset(l):
    return chain.from_iterable(combinations(l,r) for r in range(len(l),-1,-1))

def solve(forest): # TODO
    list = []
    for tree in forest:
        for s in powerset(forest):
            if tree in convex_hull(s):
                print(len(forest)-len(s))
                break
    return list


from sys import argv

for (i, case) in enumerate(load_file(argv[1])):
    print("Case #" + str(i+1) + ":")
    solve(case)

