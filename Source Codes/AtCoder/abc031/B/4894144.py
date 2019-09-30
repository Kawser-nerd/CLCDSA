import math
def getInt(): return int(input())
def getIntList(): return [int(x) for x in input().split()]
def zeros(n): return [0]*n
def zeros2(n, m): return [zeros(m) for i in range(n)] # obsoleted zeros((n, m))???

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
    L, H = getIntList()
    d.dmp((L, H), 'L, H')
    N = getInt()
    d.dmp((N), 'N')
    for i in range(N):
        a = getInt()
        #d.dmp((a), 'a')
        if a > H:
            print(-1)
        elif a >= L:
            print(0)
        else:
            print(L-a)
    return


ans = prob()