def getInt(): return int(input())
def getIntList(): return [int(x) for x in input().split()]
def zeros(n): return [0]*n

INF = 10**18

class Debug():
    def __init__(self):
        self.debug = True
 
    def off(self):
        self.debug = False
 
    def dmp(self, x, cmt=''):
        if self.debug:
            if cmt != '':
                w = cmt + ': ' + str(x)
            else:
                w = str(x)
            print(w)
        return x

def prob():
    d = Debug()
    d.off()
    N = getInt()
    d.dmp((N),'N')
    A = zeros(N)
    adic = {}
    for i in range(N):
        A[i] = getInt()
        adic[A[i]] = 0
    #d.dmp((A),'A')
    #d.dmp((adic),'adic')
    ordered = sorted(list(adic.keys()))
    #d.dmp((ordered),'ordered')
    for i in range(len(ordered)):
        adic[ordered[i]] = i
    #d.dmp((adic),'adic')
    for x in A:
        print(adic[x])
    return


ans = prob()