#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 2
problem = "D"
practice = False

if practice:
    practice = "-practice"
else:
    practice = ""
if case == 0:
    infile = open("%s-%s%s.in" % (problem, "sample", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "sample", practice), 'w')        
elif case == 1:
    infile = open("%s-%s%s.in" % (problem, "small", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "small", practice), 'w')    
elif case == 2:
    infile = open("%s-%s%s.in" % (problem, "large", practice), 'r')
    outfile = open("%s-%s%s.out" % (problem, "large", practice), 'w')   
else:
    raise ValueError, 'Invalid case'
print infile, outfile

def gcd(m, n):
    while n:
        m,n=n,m%n
    return m
    
path_cache = {}
    
def gen_path(x, y):

    if (x, y) in path_cache:
        return path_cache[(x, y)]

    assert x >= 0
    assert y >= 0
    output = []
    a = max(abs(x), abs(y))
    b = min(abs(x), abs(y))
    
    if b == 0:
        for i in xrange(a+1):
            output.append((i,0))
    else:    
        ratio = float(a) / float(b)
    
        finished = False
        pos = [0.5, 0.5]
        output.append((0, 0))
        while not finished:
            #print pos
            adist = N.floor(pos[0]) + 1 - pos[0]
            bdist = N.floor(pos[1]) + 1 - pos[1]
        
            #print adist, bdist, bdist * ratio
        
            if abs(adist - bdist * ratio) < 0.0001:
                #print 'trace1'
                pos[0] = N.floor(pos[0]) + 1
                pos[1] = N.floor(pos[1]) + 1
                output.append((int(pos[0]), int(pos[1])))
            elif adist < bdist * ratio:
                #print 'trace2'
                pos[0] = N.floor(pos[0]) + 1
                pos[1] += adist / ratio
                output.append((int(pos[0]), int(pos[1])))
            else:
                #print 'trace3'
                pos[0] += bdist * ratio
                pos[1] = N.floor(pos[1]) + 1
                output.append((int(pos[0]), int(pos[1])))
            if int(pos[0]) == a and int(pos[1]) == b:
                finished = True

    if x >= y:
        path_cache[((x, y))] = output
        return output
    else:
        new = []
        for item in output:
            new.append((item[1], item[0]))
        path_cache[(x, y)] = new
        return new
    
def look_towards(grid, visible, start, center, xmod, ymod, distsqr):
    xdirect = N.sign(xmod)
    ydirect = N.sign(ymod)
    
    xorg = xmod
    yorg = ymod
    
    xdist = abs(xmod)
    ydist = abs(ymod)
    
    position = [start[0], start[1]]
    
    path = gen_path(xdist, ydist)
    
    completed = False
    dead = False
    #print 'trace1'
    while True:
        #leave if we're outside the grid
        if center[0]+xmod >= visible.shape[0]:
            return
        if center[1]+ymod >= visible.shape[1]:
            return
        if center[0]+xmod < 0:
            return
        if center[1]+ymod < 0:
            return
            
        #if the distance is too big, set the grid
        if xmod**2 + ymod**2 > distsqr:
            visible[center[0]+xmod, center[1]+ymod] = 0
            #print visible, position, 1
            completed = True
        
        if not completed:
            #print 'trace'
            for i in range(len(path) - 1):
                x = (path[i+1][0] - path[i][0]) * xdirect
                y = (path[i+1][1] - path[i][1]) * ydirect
                
                #The next square is empty (0) or has a reflection (-1): move there
                #print grid, position
                if grid[position[0]+x, position[1]+y] <= 0:
                    position[0] += x
                    position[1] += y
                #Otherwise, there's a mirror:
                else:
                    #Corners:
                    if abs(x) > 0 and abs(y) > 0:
                        #print xmod, ymod, path, 'corner'
                        #Check the neighboring mirrors
                        xref = grid[position[0]+x, position[1]] == 1
                        yref = grid[position[0], position[1]+y] == 1
                        
                        #print xref, yref
                        
                        #If no neighboring mirrors on the corner, we die without seeing an image
                        if xref == False and yref == False:
                            visible[center[0]+xmod, center[1]+ymod] = 0
                            dead = True
                            #print visible, position, 2
                            completed = True
                        #Otherwise, reflect
                        else:
                            if xref and yref:
                                xdirect *= -1
                                ydirect *= -1
                            elif xref:
                                xdirect *= -1
                                position[1] += y
                            elif yref:
                                position[0] += x
                                ydirect *= -1
                        
                    #If there isn't a corner, stay where we are, but reflect direction
                    else:
                        if abs(x) > 0:
                            xdirect *= -1
                        elif abs(y) > 0:
                            ydirect *= -1
                        else:
                            raise ValueError, 'Empty move'
        
            #Final square:
            if (grid[position[0], position[1]] == -1) and not dead:
                visible[center[0]+xmod, center[1]+ymod] = 1
                #print visible, position, 3
                completed = True
            else:
                visible[center[0]+xmod, center[1]+ymod] = 0
                #print visible, position, 4
                
        #We're just going out again to mark ones further out as done
        else:
            #print center, xmod, ymod
            visible[center[0]+xmod, center[1]+ymod] = 0
            #print visible, position, 5
        
        #We didn't hit anything, keep going around again
        xmod += xorg
        ymod += yorg
    return
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for z in range(cases):
    print 'case %i of %i' % (z+1, cases)
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    line = infile.readline().split()
    H = int(line[0])
    W = int(line[1])
    D = int(line[2])
    grid = N.empty((H, W), dtype=int)
    
    start = [-1, -1]
    
    for j in range(H):
        line = infile.readline().strip('\n')
        for k, char in enumerate(line):
            if char == '#':
                grid[j,k] = 1
            elif char == 'X':
                grid[j,k] = -1
                start = [j, k]
            else:
                grid[j,k] = 0
    
    #Do calculations to generate the output
    
    #Build a visible square grid D*2+1 
    visible = -1 * N.ones((D*2+1, D*2+1), dtype=int)
    visible[D, D] = 2
    max_sqrd = D**2
    
    #distances
    ydist = N.vstack([N.arange(-D, D+1)]*(2*D+1))
    xdist = ydist.transpose()
    dist = N.concatenate((N.array([abs(xdist)]), N.array([abs(ydist)]))).max(axis=0)
    distsqr = xdist**2 + ydist**2
    visible[distsqr > max_sqrd] = 0
 
    for j in range(1, D+1):
        valid = abs(visible[dist == j]) > 0
        x_check = xdist[dist == j][valid]
        y_check = ydist[dist == j][valid]
        for k in range(len(x_check)):
            div = gcd(abs(x_check[k]), abs(y_check[k]))
            look_towards(grid, visible, start, [D, D], x_check[k]/div, y_check[k]/div, max_sqrd)
    
    count = (visible == 1).sum()
         
    #print visible
    #print count
 
    assert (visible == -1).sum() == 0
    
    output = '%i' % count
    
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (z+1, output))
    
#Close files
infile.close()
outfile.close()