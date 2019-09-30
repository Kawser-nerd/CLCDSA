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

def prob():  # WA 2
    d = Debug()
    d.off()
    N = getInt()
    d.dmp((N), 'N')
    L = getIntList()
    d.dmp((L), 'L')
    L.sort()
    count = 0
    for i in range(N):
        count += min(L[i*2], L[i*2+1])
    return count


ans = prob()
print(ans)