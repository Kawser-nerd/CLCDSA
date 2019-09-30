#from __future__ import division
#from math import log

# code jam template
filein="A.in"
fileout="A.out"

def solve(row):
#    if len(row)==1:
#        return 0
    chars=[]
    for c in row:
        if not(c in chars):
            chars.append(c)
    base=max(2,len(chars))
    trans=[1,0]+range(2,base)
    d=dict(zip(chars,trans))
    digits=[d[x] for x in row]
    ans=0
    for i in range(len(digits)):
        ans=ans*base+digits[i]
    return ans            

# load data
# paste basic example
datain="""
3
11001001
cats
zig
"""
#or
datain=open(filein).read()
dataout=open(fileout,"w")

# data as lines of data
data=[x for x in datain.split('\n') if x]

N=data[0]
for i,row in enumerate(data[1:]):
    text='Case #'+str(i+1)+': '+str(solve(row))

    # "text" is the output string for one case
    dataout.write(text+'\n')
    print text
    

# close data file
dataout.close()
print "Wrote %s" % fileout

