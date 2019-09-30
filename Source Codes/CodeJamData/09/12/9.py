import sys

def main(argv):
    ifilename = argv[1]
    ofilename = argv[2]
    ifile = open(ifilename, 'r')
    ofile = open(ofilename, 'w')
    
    numlines = ifile.readline().strip()
    
    solver = Solver()
        
    for i in range(int(numlines)):
        nm = ifile.readline().strip().split(" ")
        N,M = int(nm[0]),int(nm[1])
        intersections = []
        for j in range(N):
            interrow = []
            row = ifile.readline().strip().split(" ")
            for k in range(0, M*3, 3):
                inter = Intersection(int(row[k]), int(row[k+1]), int(row[k+2]))
                interrow.append(inter)
            intersections.append(interrow)
        answer = solver.solve(N, M, intersections)
        ofile.write("Case #"+str(i+1)+": "+str(answer)+"\n")
    
    ifile.close()
    ofile.close()
    
class Solver:
    intersections = []
    times = []
    visited = []
    N = 0
    M = 0
    
    def solve(self, N, M, intersections):
        self.intersections = intersections
        self.N = N
        self.M = M
        
        times = [[-1 for x in range(2*M)] for y in range(2*N)]
        visited = [[False for x in range(2*M)] for y in range(2*N)]
        times[2*N-1][0] = 0
        visited[2*N-1][0] = True
        
        while times[0][2*M-1] == -1:
            minimum = -1
            xn = 0
            yn = 0
            for y in range(2*N):
                n = y/2
                for x in range(2*M):
                    m = x/2
                    if times[y][x] != -1:
                        #east side of intersection
                        if x%2 == 1:
                            #time to cross west
                            crossingt = times[y][x] + intersections[n][m].nextGreenEW(times[y][x]) + 1
                            if x-1 >= 0 and times[y][x-1] == -1:
                                if minimum == -1 or crossingt < minimum:
                                    minimum = crossingt
                                    xn = x-1
                                    yn = y
                            #go a block east
                            if x+1 < 2*M and times[y][x+1] == -1:
                                if minimum == -1 or times[y][x]+2 < minimum:
                                    minimum = times[y][x]+2
                                    xn = x+1
                                    yn = y
                        #west side of intersection
                        else:
                            #go a block west
                            if x-1 >= 0 and times[y][x-1] == -1:
                                if minimum == -1 or times[y][x]+2 < minimum:
                                    minimum = times[y][x]+2
                                    xn = x-1
                                    yn = y
                            #time to cross east
                            crossingt = times[y][x] + intersections[n][m].nextGreenEW(times[y][x]) + 1
                            if x+1 < 2*M and (times[y][x+1] == -1 or times[y][x+1] > crossingt):
                                if minimum == -1 or crossingt < minimum:
                                    minimum = crossingt
                                    xn = x+1
                                    yn = y
                        #north side of intersection
                        if y%2 == 0:
                            #time to cross south
                            crossingt = times[y][x] + intersections[n][m].nextGreenNS(times[y][x]) + 1
                            if y+1 < 2*N and (times[y+1][x] == -1 or times[y+1][x] > crossingt):
                                if minimum == -1 or crossingt < minimum:
                                    minimum = crossingt
                                    xn = x
                                    yn = y+1
                            #go a block north
                            if y-1 >= 0 and (times[y-1][x] == -1 or times[y-1][x] > times[y][x]+2):
                                if minimum == -1 or times[y][x]+2 < minimum:
                                    minimum = times[y][x]+2
                                    xn = x
                                    yn = y-1
                        #south side of intersection
                        else:
                            #go a block south
                            if y+1 < 2*N and (times[y+1][x] == -1 or times[y+1][x] > times[y][x]+2):
                                if minimum == -1 or times[y][x]+2 < minimum:
                                    minimum = times[y][x]+2
                                    xn = x
                                    yn = y+1
                            #time to cross north
                            crossingt = times[y][x] + intersections[n][m].nextGreenNS(times[y][x]) + 1
                            if y-1 >= 0 and (times[y-1][x] == -1 or times[y-1][x] > crossingt):
                                if minimum == -1 or crossingt < minimum:
                                    minimum = crossingt
                                    xn = x
                                    yn = y-1
            times[yn][xn] = minimum

        return times[0][2*M-1]
    
class Intersection:
    S = 0
    W = 0
    T = 0
    
    def __init__(self, S, W, T):
        self.S = S
        self.W = W
        self.T = T
    
    def nextGreenNS(self, t):
        t = t-self.T
        if t < 0:
            t = (t % -(self.S + self.W)) + (self.S + self.W)
        t = t % (self.S + self.W)
        if t < self.S:
            return 0
        else:
            return (self.S + self.W) - t
        
    def nextGreenEW(self, t):
        t = t-self.T
        if t < 0:
            t = (t % -(self.S + self.W)) + (self.S + self.W)
        t = t % (self.S + self.W)
        if t >= self.S:
            return 0
        else:
            return self.S - t
    
if __name__ == '__main__':
    main(sys.argv)