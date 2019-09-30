#from __future__ import division
#from math import log

# code jam template
filein="C.in"
fileout="C.out"

cache={}

def best(setsleft,todo,sofar):
    global cache
    if not(todo):
        return sofar
    key=str((setsleft,todo,sofar))
    if key in cache:
        return cache[key]
    else:
        poss=[]
        for p in todo:
            his=[x for x in setsleft if p in x][0]
            others=[x for x in setsleft if not(p in x)]
            cost=len(his)-1
            hislow=[x for x in his if x<p]
            hishigh=[x for x in his if x>p]
            otherstodo=[x for x in todo if x!=p]
            poss.append(best(others+[hislow,hishigh],otherstodo,sofar+cost))
        ans=min(poss)
        cache[key]=ans
        return ans

def solve(line1,line2):
    P,_=map(int,line1.split())
    release=map(int,line2.split())
    return best([range(1,P+1)],release,0)
            

# load data
# paste basic example
datain="""
2
8 1
3
20 3
3 6 14
"""
#or
datain=open(filein).read()
dataout=open(fileout,"w")

# data as lines of data
data=[x for x in datain.split('\n') if x]
N=int(data[0])
atrow=1

for case in range(N):
    text='Case #'+str(case+1)+': '+str(solve(data[atrow],data[atrow+1]))
    atrow+=2
    # "text" is the output string for one case
    dataout.write(text+'\n')
    print text
    

# close data file
dataout.close()
print "Wrote %s" % fileout

