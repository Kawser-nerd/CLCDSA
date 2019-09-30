def reader(inFile):
    dummy = inFile.getInt()
    return (inFile.getInts(), inFile.getInts())

class Queue:
    def __init__(self, x):
        self.q = x
        self.qat = 0
        self.qlen = len(x)
    
    def pop(self):
        self.qat += 1
        return self.q[self.qat - 1]
    
    def elements(self):
        while (not self.empty()):
            yield self.pop()

    def push(self, x):
        self.q.append(x)
        self.qlen += 1

    def empty(self):
        return self.qat == self.qlen

def solver((a,b)):
    N = len(a)
    lwrs = [[] for i in xrange(N)] 
    uprs = [[] for i in xrange(N)]
    last = {}
    for i in xrange(N):
        if last.has_key(a[i]):
            lwrs[last[a[i]]] += [i]
        last[a[i]] = i
        if a[i] > 1:
            lwrs[i] += [last[a[i]-1]]
            uprs[last[a[i]-1]] += [i]
    last = {}
    for i in xrange(N - 1, -1, -1):
        if last.has_key(b[i]):
            lwrs[last[b[i]]] += [i]
        last[b[i]] = i
        if b[i] > 1:
            lwrs[i] += [last[b[i]-1]]
            uprs[last[b[i]-1]] += [i]
    
    #print lwrs
    ans = [0] * N
    for i in xrange(N):
        inQ = [False] * N
        q = Queue([i])
        inQ[i] = True
        for j in q.elements():
            for l in lwrs[j]:
                if not inQ[l]:
                    q.push(l)
                    inQ[l] = True
        ans[i] = q.qlen
        for j in xrange(N):
            if not inQ[j]:
                lwrs[j] += [i]
    return " ".join([str(z) for z in ans])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_2/c/", "c").run()
