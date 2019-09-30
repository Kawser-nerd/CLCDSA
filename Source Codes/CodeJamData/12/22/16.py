#!/usr/bin/env python

import fileinput, collections, sys, operator, itertools

def autodict():
    return collections.defaultdict(autodict)

def input():
    it = iter(itertools.imap(str.rstrip, fileinput.input()))
    it.next()
    while True:
        h, n, m = map(int, it.next().rstrip().split())
        ceil = []
        floor = []
        for i in range(n):
            ceil.append(
                map(int, it.next().rstrip().split()))
        for i in range(n):
            floor.append(
                map(int, it.next().rstrip().split()))
        yield (h, n, m, ceil, floor)

def main():
    for casenum, (h, rows, cols, ceil, floor) in enumerate(input()):

        def timeToMove(fromx, fromy, tox, toy, startTime):
            water = h - startTime * 10
            if tox < 0 or tox >= cols or toy < 0 or toy >= rows:
                return None
            toceil = ceil[toy][tox]
            if (toceil - floor[fromy][fromx] < 50 or
                toceil - floor[toy][tox] < 50):
                return None
            if ceil[fromy][fromx] - floor[toy][tox] < 50:
                return None
            if toceil - water >= 50 and startTime == 0:
                return 0

            t = 0
            if toceil - water < 50:
                t = (50. - toceil + water) / 10
                water = max(0, toceil - 50)
            if water - floor[fromy][fromx] >= 20:
                return t + 1
            else:
                return t + 10

        bestTimes = [
            [None for i in range(cols)] for i in range(rows)]
        bestTimes[0][0] = 0
        frontier = set([(0,0)])

        while frontier:
            #print frontier
            #print bestTimes
            for x,y in frontier:
                break
            for xx,yy in frontier:
                if bestTimes[yy][xx] < bestTimes[y][x]:
                    y=yy;x=xx
            frontier.remove((x,y))
            #print x,y

            if x == cols-1 and y == rows-1:
                break
            for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
                newx=x+dx; newy=y+dy
                time = bestTimes[y][x]
                ttm = timeToMove(x,y,newx,newy,time)
                #print 'ttm', ttm
                if ttm == None: continue
                newTime = time + ttm
                if bestTimes[newy][newx] == None:
                    bestTimes[newy][newx] = newTime
                    frontier.add((newx,newy))
                elif newTime < bestTimes[newy][newx]:
                    bestTimes[newy][newx] = newTime

        #print frontier
        #print bestTimes

        # code
        res = bestTimes[rows-1][cols-1]
        print "Case #%d: %f" % (casenum+1, res)

main()
