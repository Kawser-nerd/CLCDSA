'''
Google CodeJam 2009 - Round 1B - Problem B

@author: Dan Bjorge
'''

#fileprefix = 'B-small-ex'
#fileprefix = 'B-small-attempt0'
fileprefix = 'B-large'

filepath = ''
filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

#This will sometimes, but not often, change
linenum = 1
cases = int(lines[0])

def solve(n):
    D = [-1] + [0 for i in range(9)]
    for ch in n:
        i = int(ch)
        if i != 0:
            D[int(ch)]+=1
    
    digits = len(n)
    
    biggest = ""
    for i in range(9,0,-1):
        biggest += str(i)*D[i]
    
    biggest += "0"*(digits-len(biggest))
    
    if n == biggest:
        smallest = ""
        for i in range(1, 10):
            smallest += str(i)*D[i]
        smallest = smallest[0]+("0"*(digits+1-len(smallest)))+smallest[1:]
        return smallest
    else:
        cur = int(n[-1])
        rest = [cur]
        max = cur
        for i in range(digits-2, -1, -1):
            #print("considered "+str(cur)+": was maximal in "+str(rest))
            cur = int(n[i])
            if cur >= max:
                rest.append(cur)
                max = cur
            else:
                #print(str(cur)+" was the pivot!")
                rest.sort()
                for j in range(len(rest)):
                    if rest[j] > cur:
                        switched = j
                        break
                r = n[:i]+str(rest[switched])
                for l in rest[:switched]:
                    r += str(l)
                r += str(cur)
                for m in rest[switched+1:]:
                    r += str(m)
                
                return r
        
        return -1
            
            
            

for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum

    out = solve(lines[linenum]) #Assign solved value
    linenum+=1
    
    #End parsing - start outputting
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")