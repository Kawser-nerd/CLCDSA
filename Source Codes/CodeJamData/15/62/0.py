def reader(inFile):
    return tuple(inFile.getInts())

N = 10 ** 9 + 7

fc = [1]
for i in xrange(1,10**6+1):
    fc.append((fc[-1] * i) % N)

fc2 = [pow(z,N-2,N) for z in fc]

def combin(n,k):
    return fc[n]*fc2[k]*fc2[n-k]

w = [-1, 0, 1, 1, 3]
for i in xrange(5, 10**6+1):
    w.append((w[i - 1] * (i - 1) - w[i - 3] * (i - 4)) % N)

w = [(w[i] * fc[i] * (i - 1)) % N for i in xrange(len(w))]

def g(z):
    return w[z]

def f(N,i):
    return ((combin(N,i)**2)*fc[i]*g(N-i)) % (10 ** 9 + 7)

def solver((N,X)):
    return sum(f(N,i) for i in xrange(X,N+1)) % (10 ** 9 + 7)

if __name__ == "__main__":
    # GCJ library publically available at http://ideone.com/2PcmZT
    from GCJ import GCJ
    GCJ(reader, solver, r"C:\gcj\finals\b", "b").run()

