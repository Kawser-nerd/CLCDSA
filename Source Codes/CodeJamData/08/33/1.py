import sys
import math

MOD = 1000000007

class RangeStor:
    def __init__(self, a, b, lst):
        self.a = a
        self.b = b
        self.val = 0
        self.lst = lst
        self.split = None
        if b-a>20:
            self.split = (a+b)//2
            self.ch1 = RangeStor(a, self.split, lst)
            self.ch2 = RangeStor(self.split, b, lst)
    def sum(self, x):
        if x<=self.a:
            return 0
        if x>=self.b:
            return self.val
        if self.split:
            return self.ch1.sum(x) + self.ch2.sum(x)
        res = 0
        for i in range(self.a, x):
            res += self.lst[i]
        return res%MOD
    def addTo(self, x, V):
        if x<self.a or x>=self.b:
            return
        if self.split:
            self.ch1.addTo(x, V)
            self.ch2.addTo(x, V)
            self.val += V
        else:
            self.lst[x] += V
            self.val += V
            

def do_test(input):
    line = input.readline().split(' ')
    n = int(line[0])
    m = int(line[1])
    X = int(line[2])
    Y = int(line[3])
    Z = int(line[4])
    A = []
    for i in range(m):
        A.append(int(input.readline()))
    speed = []
    for i in range(n):
        speed.append(A[i%m])
        A[i%m] = (X*A[i%m] + Y* (i+1)) % Z

    sp2 = list(speed)
    sp2.sort()
    sp2map = {}
    last = -10
    for x in range(len(sp2)):
        if sp2[x]!=last:
            sp2map[sp2[x]] = x
        last = sp2[x]
    for x in range(len(speed)):
        speed[x] = sp2map[speed[x]]

    rs = RangeStor(0, n, [0]*n)

    for x in speed:
        s = rs.sum(x) + 1
        rs.addTo(x, s)
    
    return rs.sum(n+1)%MOD

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)d' % \
        {'case': test+1, 'answer': answer}
