'''Google CodeJam 2009 - Round 1B - Problem A

@author: Dan Bjorge
'''

#fileprefix = 'A-small-ex'
#fileprefix = 'A-small-attempt0'
fileprefix = 'A-large'

filepath = ''
filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

#This will sometimes, but not often, change
linenum = 1
cases = int(lines[0])
class Tree:    def __init__(self, p, feature="", t1=None, t2=None):        self.p = p        self.feature = feature        self.t1 = t1        self.t2 = t2                self.isLeaf = (feature == "")    def getP(self, features, p):        p *= self.p        if not self.isLeaf:            if self.feature in features:                return self.t1.getP(features, p)            else:                return self.t2.getP(features, p)        else:            return p            def __str__(self):        r = "["+str(self.p)        if self.isLeaf:            return r+"]"        return r+" "+self.feature+" "+str(self.t1)+" "+str(self.t2)+"]"        def parseTree(str):    str = str.strip()    if str == "":        return None    else:        if str[0] != '(' or str[-1] != ')':            raise Exception("malformed tree")        str = str[1:-1].strip()        if ' ' in str:            spaceIndex = str.index(" ")            prob = float(str[0:spaceIndex])            str = str[spaceIndex+1:].strip()            spaceIndex = str.index(" ")            feature = str[0:spaceIndex]            str = str[spaceIndex+1:].strip()            if str[0] != '(':                raise Exception("malformed tree")                        c=1            p=1            while p>0:                if str[c] == '(':                    p+=1                elif str[c] == ')':                    p-=1                c+=1                        t1 = parseTree(str[0:c])            str = str[c+1:].strip()            t2 = parseTree(str)            return Tree(prob, feature, t1, t2)        else:            return Tree(float(str))                        def parseAnimal(line):    words = line.split(" ")    n = int(words[1])    if n == 0:        return (words[0], [])    else:        return (words[0], words[2:])def solve(animal, tree):    return tree.getP(animal[1], 1.0)
for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum
    L = int(lines[linenum])    linenum += 1    tree = parseTree(" ".join(lines[linenum:linenum+L]))    #print(str(tree))    linenum += L    A = int(lines[linenum])    linenum += 1    animals = [parseAnimal(line) for line in lines[linenum:linenum+A]]    linenum += A    out = ""        for animal in animals:        out += "\n" + ( "%.8f" % solve(animal, tree))
    
    #End parsing - start outputting
    casestr = 'Case #'+str(casenum)+': '+ out
    print (casestr)
    outfile.write(casestr+"\n")