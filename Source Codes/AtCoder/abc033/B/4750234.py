def getInt(): return int(input())
def getIntList(): return [int(x) for x in input().split()]
def zeros(n): return [0]*n

class Debug():
    def __init__(self):
        self.debug = True

    def off(self):
        self.debug = False

    def dmp(self, x, cmt=''):
        if self.debug:
            if cmt != '':
                print(cmt, ':  ', end='')
            print(x)
        return x


def prob():
    N = getInt()
    s = zeros(N)
    p = zeros(N)
    for i in range(N):
        s[i], p[i] = [x for x in input().split()]
        p[i] = int(p[i])
    d = Debug()
    d.off()
    d.dmp((N),'N')
    d.dmp((s),'s')
    d.dmp((p),'p')
    if max(p)*2 > sum(p):
        for i in range(N):
            if p[i] == max(p):
                print(s[i])
                break
    else:
        print('atcoder')

a = prob()