# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 2, 2009-09-26

import itertools
import math

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def solve_third_case(points):
    solution = 10**10
    for p in itertools.permutations([0, 1, 2], 3):
        foobar = distance(points[p[0]], points[p[1]])
        foobar = (foobar + points[p[0]][2] + points[p[1]][2]) / 2
        if foobar >= points[p[2]][2]:
            solution = min([solution, foobar])
        else:
            solution = min([solution, points[p[2]][2]])
    return solution        

def solve(points):
    if len(points) == 1:
        return points[0][2]
    elif len(points) == 2:
        return max(points[0][2], points[1][2])
    elif len(points) == 3:
        return solve_third_case(points)

def main():
    file = open("input.in")
    tests = int(file.readline())
    for case in range(1, tests + 1):
        N = int(file.readline())
        points = []
        for i in range(N):
            points.append([int(x) for x in file.readline().split()])
        print("Case #", case, ": ", solve(points), sep="")

if __name__ == "__main__":
    main()
