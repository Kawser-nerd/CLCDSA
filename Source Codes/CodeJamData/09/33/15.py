import sys
import math

fin=open('input.txt','r')
fout=open('output.txt','w')

l=int(fin.readline())
for case in range(l):
    P,Q=map(int,fin.readline().strip().split())
    frees=map(int,fin.readline().strip().split())
    
    cache={}
    
    def rangeof(lid,rid):
        lrange=rrange=0
        if lid==0:
            lrange=1
        else:
            lrange=frees[lid-1]+1
        if rid==len(frees)-1:
            rrange=P
        else:
            rrange=frees[rid+1]-1
        return rrange-lrange+1
    
    def getbetter(lid,rid):
        if lid>rid:
            return 0
        if lid==rid:
            return rangeof(lid,rid)-1
        key=(lid,rid)
        if key in cache:
            return cache[key]
        else:
            for i in range(lid,rid+1):
                cache[key]=rangeof(lid,rid)-1+min([getbetter(lid,i-1)+getbetter(i+1,rid) for i in range(lid,rid+1)])
            return cache[key]
        
    
    fout.write("Case #%d: %d\n"%(case+1,getbetter(0,len(frees)-1)))
 
fin.close()
fout.close()
