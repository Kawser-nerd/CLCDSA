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
    S = input()
    d.dmp((S),'S')
    count = 0
    zeroFound = False
    for c in S:
        if c == '0':
            zeroFound = True
        elif c == '+':
            if zeroFound:
                zeroFound = False
            else:
                count += 1
    if not zeroFound:
        count += 1
    return count


ans = prob()
print(ans)