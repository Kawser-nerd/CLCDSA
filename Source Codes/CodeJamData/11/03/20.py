#!/usr/bin/env python
import sys

def cal(seq):
    seq = [int(i) for i in seq]
    if reduce(lambda a,b: a^b, seq):
        return False
    seq.sort()
    return sum(seq[1:])

def wf(fileName,results):
    f = open(fileName,'w')
    for i,r in enumerate(results):
        f.write('Case #%d: %s\n'%(i+1,r))
    f.close()

def rf(fileName):
    f = open(fileName,'r')
    inputs = []
    n = int(f.readline())
    for i in range(n):
        l = f.readline()
        inputs.append(l)
        l = f.readline()
        inputs.append(l)
    return inputs
   
if __name__=='__main__':
    inputs = rf(sys.argv[-1])
    #inputs = ['5','1 2 3 4 5']
    #inputs = ['3','3 5 6']
    print inputs

    results = []
    for i,ip in enumerate(inputs):
        if not i%2:
            continue
        print i,ip
        seq = ip.split()
        rt = cal(seq)
        if rt:
            results.append(str(rt))
        else:
            results.append('NO')
    wf(sys.argv[-1][:-2]+'out',results)

