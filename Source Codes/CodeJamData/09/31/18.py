import sys

fin=open('input.txt','r')
fout=open('output.txt','w')

l=int(fin.readline())
for case in range(l):
    v=fin.readline().strip()
    
    alen=len(set(list(v)))
    if alen<2:
        alen=2
    
    val=0
    mapping={}
    usable=0
    first=True
    
    for i in v:
        val*=alen
        if i not in mapping:
            if first:
                mapping[i]=1
                first=False
            else:
                if usable==0:
                    mapping[i]=0
                else:
                    mapping[i]=usable+1
                usable+=1
        val+=mapping[i]
        
    fout.write("Case #%d: %d\n"%(case+1,val))

fin.close()
fout.close()
