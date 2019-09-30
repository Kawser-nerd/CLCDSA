import io, sys
import datetime, copy

fin = None


def solve():
    n = num()
    e = [x-1 for x in nums()]
    invs = [[] for i in range(n)]
    for i in range(n):
        invs[e[i]].append(i)    
    step = {}
    res = 0
    
    def depth(v, ignore):
        #print(v)
        res = 0
        for u in invs[v]:
            if u == ignore:
                continue
            res = max(res, depth(u, -1) + 1)
        return res
    
    sum = 0
    for i in range(n):
        if i not in step:
            t = 0
            v = i
            vers = []
            while v not in step:
                step[v] = t
                t += 1
                vers.append(v)
                v = e[v]
            if v not in vers:
                continue
            le = t - step[v]
            #print(vers)
            vers = vers[-le :]   
            res = max(res, len(vers))
            #print(vers)
            if len(vers) == 2:
                sum += 2 + depth(vers[0], vers[1]) + depth(vers[1], vers[0])            
            
    return max(res, sum) 
                     
        
    
        
        
def main():
    fname = 'a.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    global fin    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve()))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()

def nums():
    return [int(x) for x in fin.readline().split()]
def fnums():
    return [float(x) for x in fin.readline().split()]
def num():
    return int(fin.readline())
def sstrip():
    return fin.readline().strip()
def strs():
    return fin.readline().split()
def arrstr(a, sep = ' '):
    return sep.join([str(x) for x in a])

if __name__ == '__main__':
    main()
    #print(solvex(1, 9, 6))
    #solveb_meta()