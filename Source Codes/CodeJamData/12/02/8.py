#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 2
problem = "B"
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
    
#Hash table:  -1 is never, +1 is always, 0 is sometimes
lookup = {}

def check_total(total, p):
    assert type(total) == int
    resid = total % 3

    min_nosurprise = (total / 3)    
    max_nosurprise = (total / 3) + min(1, resid)
    
    #print min_nosurprise, max_nosurprise
    
    #If the residual is 1, then being surprising won't change the max value
    #similarly, if we're already at the maximum, it can't change
    #similarly, if residual is 0 and the min value is already 0, it can't change
    if resid == 1 or max_nosurprise == 10 or (resid == 0 and min_nosurprise == 0):
        if max_nosurprise >= p:
            return 1
        else:
            return -1

    if max_nosurprise >= p:
        return 1
    elif max_nosurprise == p-1:
        return 0
    else:
        return -1
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for i in range(cases):
    print 'case %i of %i' % (i+1, cases)
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    line = infile.readline().split()
    N = int(line[0])
    S = int(line[1])
    p = int(line[2])
    points = []
    for item in line[3:]:
        points.append(int(item))
    assert N == len(points)
    assert p <= 10
    assert p >= 0
    assert S >= 0
    assert S <= N
    
    always = 0
    possible = 0
    
    for total in points:
        if (total, p) in lookup:
            depends = lookup[total, p]
        else:
            depends = check_total(total, p)
        
        if depends == 1:
            always += 1
        elif depends == 0:
            possible += 1
    
    #Do calculations to generate the output
    output = '%i' % (always + min(possible, S))
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (i+1, output))
    
#Close files
infile.close()
outfile.close()