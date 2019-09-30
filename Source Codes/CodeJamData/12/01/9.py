#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N
from string import translate, maketrans

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 1
problem = "A"
practice = False

if practice:
    practice = "-practice"
else:
    practice = "-attempt0"
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
    
alpha = 'abcdefghijklmnopqrstuvwxyz '
trans = 'ynficwlbkuomxsevzpdrjgthaq '
table = maketrans(trans, alpha)
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for i in range(cases):
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    instr = infile.readline().strip('\n')
    
    #Do calculations to generate the output
    
    output = translate(instr, table)
    
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (i+1, output))
    
#Close files
infile.close()
outfile.close()