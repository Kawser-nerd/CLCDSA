import time
import sys
from math import sqrt
import math

def euclidean(a, b):
    if a == 0:
        return b
    elif b == 0:
        return a
    
    while (a != 0 and b != 0):
        if a > b:
            a = a%b
        else:
            b = b%a
    
    if (a == 0):
        return b
    else:
        return a

EMPTY_VAL = 0
MIRROR_VAL = 1

class Line:
    def __init__(self, xperiod, yperiod, xdist, ydist):
        self.xperiod = xperiod
        self.yperiod = yperiod
        self.xdist = xdist
        self.ydist = ydist
        
        self.xstep = 0
        self.ystep = 0
        self.xtraveled = 0
        self.ytraveled = 0
    
    def eval(self, grid, startloc, xsign, ysign):
        currloc = startloc
        while (self.xtraveled <= self.xdist and self.ytraveled <= self.ydist):
            '''
            while (self.xstep < self.xperiod and self.ystep < self.yperiod):
                self.xstep += 1
                self.ystep += 1
                if currloc == startloc and (self.xstep == 0 or self.xperiod == sys.maxint) and (self.ystep == 0 or self.yperiod == sys.maxint):
                    return True
            '''
            if (currloc == startloc and ((self.xstep == self.ystep and self.xstep < 0) or (self.xstep < 0 and self.yperiod == sys.maxint) or (self.ystep < 0 and self.xperiod == sys.maxint))):
                return True
            numxsteps = xperiod - self.xstep
            numysteps = yperiod - self.ystep
            minstep = min(numxsteps, numysteps)
            self.xstep += minstep
            self.ystep += minstep
            
            
            
            if self.xstep == self.xperiod and self.ystep == self.yperiod:
                #corner
                nextloc = (currloc[0]+xsign, currloc[1]+ysign)
                if grid[nextloc[0]][nextloc[1]] == EMPTY_VAL:
                    currloc = nextloc
                else:
                    if grid[nextloc[0]][currloc[1]] == EMPTY_VAL:
                        if grid[currloc[0]][nextloc[1]] == EMPTY_VAL:
                            #destroy
                            return False
                        else:
                            #same-y empty, same-x full
                            #reflect y
                            ysign = -ysign
                            currloc = (nextloc[0], currloc[1])
                    else:
                        if grid[currloc[0]][nextloc[1]] == EMPTY_VAL:
                            #same-x empty, same-y full
                            #reflect x
                            xsign = -xsign
                            currloc = (currloc[0], nextloc[1])
                        else:
                            #all full, complete reflect, currloc no change
                            ysign = -ysign
                            xsign = -xsign
            elif self.xstep == self.xperiod:
                nextloc = (currloc[0]+xsign, currloc[1])
                if grid[nextloc[0]][nextloc[1]] == EMPTY_VAL:
                    currloc = nextloc
                else:
                    xsign = -xsign
            else:
                #self.ystep == self.yperiod
                nextloc = (currloc[0], currloc[1]+ysign)
                if grid[nextloc[0]][nextloc[1]] == EMPTY_VAL:
                    currloc = nextloc
                else:
                    ysign = -ysign
            
            
            if self.xstep == self.xperiod:
                self.xtraveled += 1
                self.xstep = -self.xperiod
            
            if self.ystep == self.yperiod:
                self.ytraveled += 1
                self.ystep = -self.yperiod
            #print str(currloc) + ":" + str(self.xstep) + ","+str(self.ystep)
        
        return False

with open('D-large.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for case in range(1, numcases+1):
            start = time.time()
            line = [int(j) for j in fin.readline().split()]
            rows = line[0]
            cols = line[1]
            dist = line[2]
            sqdist = dist*dist
            grid = [[None for j in range(cols)] for i in range(rows)]
            startloc = None
            for i in range(rows):
                line = fin.readline()
                for j in range(cols):
                    if line[j] == '#':
                        grid[i][j] = MIRROR_VAL
                    elif line[j] == '.':
                        grid[i][j] = EMPTY_VAL
                    else:
                        grid[i][j] = EMPTY_VAL
                        startloc = (i, j)
            
            pathset = set({})
            count = 0
            
            for i in range(-dist, dist+1):
                for j in range(-dist, dist+1):
                    localsq = i*i+j*j
                    if (localsq <= sqdist and localsq > 0):
                        gcd = euclidean(abs(i), abs(j))
                        leasti = i/gcd
                        leastj = j/gcd
                        if (leasti, leastj) not in pathset:
                            pathset.add((leasti, leastj))
                            if leasti == 0:
                                yperiod = 1
                                xperiod = sys.maxint
                            elif leastj == 0:
                                xperiod = 1
                                yperiod = sys.maxint
                            else:
                                yperiod = abs(leasti)
                                xperiod = abs(leastj)
                            if leasti >= 0:
                                xsign = 1
                            else:
                                xsign = -1
                            if leastj >= 0:
                                ysign = 1
                            else:
                                ysign = -1
                            localdist = sqrt(leasti*leasti + leastj*leastj)
                            mult = int(math.floor(dist / localdist))
                            #print str(leasti) + "," +str(leastj)+","+str(mult)+","+str(xperiod)+","+str(yperiod)
                            newline = Line(xperiod, yperiod, abs(leasti)*mult, abs(leastj)*mult)
                            if newline.eval(grid, startloc, xsign, ysign):
                                count += 1
            
            
            fout.write("Case #")
            fout.write(str(case))
            fout.write(": ")
            fout.write(str(count))
            fout.write('\n')
            print str(case) + " " + str(time.time() - start)
