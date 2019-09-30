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
    S = input()
    d.dmp((S), 'S')
    T = getInt()
    d.dmp((T), 'T')
    x, y, q = 0, 0, 0
    for i in range(len(S)):
        if S[i] == 'R':
            x += 1
        elif  S[i] == 'L':
            x -= 1
        elif S[i] == 'U':
            y += 1
        elif  S[i] == 'D':
            y -= 1
        else:
            q += 1
    val = abs(x) + abs(y)
    if T == 1:
        val += q
    else:
        if val >= q:
            val -= q
        else:
            val = (q - val) % 2
    return val


ans = prob()
print(ans)