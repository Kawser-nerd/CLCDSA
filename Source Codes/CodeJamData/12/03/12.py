#Code copyright Brett Olsen, 2012

#Standard imports
import numpy as N

#Some switching behavior to set standard input/output files
#Set these three variables to adjust behavior
case = 2
problem = "C"
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
    
def permute(num, maxval):
    assert type(num) == int
    output = []
    digits = int(N.ceil(N.log10(num)))
    current = num
    for i in range(digits-1):
        current = current / 10 + 10**(digits-1) * (current % 10)
        if current <= num: #We only want permutations greater than num (for uniqueness)
            continue
        if current > maxval: #only permutations less than the maximum value
            continue
        if current not in output:
            output.append(current)
#    return output
    return len(output)
    
def count_recycled(A, B):
    count = 0
    for num in xrange(A, B+1):
        count += permute(num, B)
    return count
    
#Read in the number of cases (the first input line) we need to iterate through
cases = int(infile.readline().strip('\n'))
for i in range(cases):
##################NEW CODE GOES HERE###########################################    
    #Read in all relevant data for each case
    A, B = infile.readline().split()
    A = int(A)
    B = int(B)
    
    #Do calculations to generate the output
    output = '%i' % count_recycled(A, B)
    
##################NEW CODE GOES HERE###########################################    
    #Write out the results for this case
    outfile.write('Case #%i: %s\n' % (i+1, output))
    
#Close files
infile.close()
outfile.close()