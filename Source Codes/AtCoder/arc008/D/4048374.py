class SegmentTree():
    def __init__(self, m, init):
        self.n = 1
        while (self.n < m):
            self.n *= 2

        self.data = [init] * (2 * self.n - 1) #2n-1?????
    
    #k?????a????
    def update(self, k, a):
        #????
        k += (self.n - 1)
        self.data[k] = a
        
        while (0 < k):
            k = (k - 1) // 2
            seg.data[k] = self.merge(k)

    def merge(self, k):
        l = self.data[2*k+1]
        r = self.data[2*k+2]
        return ((l[0] * r[0]), (r[0]*l[1]+r[1]))
    
    def get_top(self):
        return seg.data[0]


N, M = map(int, input().split())
P = []; A = []; B = []
#P????????????????????
for i in range(M):
    p, a, b = input().split();
    P.append(int(p)); A.append(float(a)); B.append(float(b))

#??????????
D = {}
q = sorted(list(set(P)))
D.update(zip(q, list(range(len(q)))))

seg = SegmentTree(M, (1,0))
min_r = 1
max_r = 1
for i in range(M):
    seg.update(D[P[i]], (A[i], B[i]))
    top = seg.get_top()
    r = top[0] + top[1]
    min_r = min(min_r, r)
    max_r = max(max_r, r)
    #print(top)

print("%.9f" % min_r)
print("%.9f" % max_r)