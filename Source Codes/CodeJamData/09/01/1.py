'''
Created on Sep 1, 2009

Codejam template

@author: Dan
'''

filepath = ''
#filepath = 'C:\Users\Dan\Downloads\'

fileprefix = 'A-large' #Change me!


filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

linenum = 1
vars = lines[0].split(' ')
cases = int(vars[2])
l = int(vars[0])
d = int(vars[1])
words = lines[1:d+1]
linenum = d+1

def explode(word):
    r = []
    
    curset = []
    
    inset = False
    
    for c in word:
        if c == '(':
            inset = True
        elif c == ')':
            inset = False
            r.append(curset)
            curset = []
        elif inset:
            curset.append(c)
        else:
            r.append([c])
            
    return r
        
        
    
def solve(word):
    possible = words[:]
    exploded = explode(word)
    for i in range(l):
        nposs = []
        for p in possible:
            if p[i] in exploded[i]:
                nposs.append(p)
        possible = nposs
    
    return len(possible)

for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum

    out = solve(lines[linenum]) #Assign solved value
    linenum+=1
    #End parsing
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")