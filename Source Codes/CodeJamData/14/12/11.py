import io, sys
import datetime

fin = None

def nums():
    return [int(x) for x in fin.readline().split()]
def fnums():
    return [float(x) for x in fin.readline().split()]
def num():
    return int(fin.readline())
def sstrip():
    return fin.readline().strip()
def arrstr(a, sep = ' '):
    return sep.join([str(x) for x in a])


def solve():
    n = num()
    edges = [[] for _ in range(n)]
    
    def dfs(v, par):
        cnt = 1
        costs = []
        for u in edges[v]:
            if u == par:
                continue
            cnt1, x1 = dfs(u, v)
            cnt += cnt1
            costs.append(x1 - cnt1)
        if len(costs) == 0:
            return cnt, 0
        if len(costs) == 1:
            return cnt, cnt - 1
        costs.sort()
        return cnt, cnt - 1 + costs[0] + costs[1] 
    
    
    for _ in range(n-1):
        u, v = nums()
        edges[u-1].append(v-1)
        edges[v-1].append(u-1)
    res = 1000000
    for i in range(n):
        k = dfs(i, -1)[1]        
        res = min(res, k)        
    return res
        
def main():
    sys.setrecursionlimit(2000)
    fname = 'a.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    global fin    
    fin = io.open(fname)
    fout = io.open(fname + '.out.txt', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve()))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()
        
if __name__ == '__main__':
    main()    