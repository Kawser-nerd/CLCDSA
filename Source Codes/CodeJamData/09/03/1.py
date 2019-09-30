'''
Created on Sep 1, 2009

Codejam template

@author: Dan
'''

filepath = ''
#filepath = 'C:\Users\Dan\Downloads\'

fileprefix = 'C-large' #Change me!


filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

cases = int(lines[0])
linenum = 1


def solve(sentence):
    fsen = ""
    search = "welcome to code jam"
    slen = len(search)
    for c in sentence:
        if c in "welcome to code jam":
            fsen += c
    
    last = [0 for i in range(slen)]
    for c in fsen:
        next = last[:]
        for i in range(slen):
            schar = search[i]
            if c == schar:
                if i == 0:
                    next[i] += 1
                else:
                    next[i] += last[i-1]
        last = next
    
    return "%04d" % (last[slen-1] % 10000) 
    
    

for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum
    out = solve(lines[casenum]) #Assign solved value
    #End parsing
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")