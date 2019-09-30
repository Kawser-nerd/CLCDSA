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
    K = getInt()
    d.dmp((S,K),'S,K')
    dic = set([])
    for i in range(len(S)-K+1):
        if S[i:i+K] not in dic:
            dic.add(S[i:i+K])
    d.dmp((dic),'dic')
    return len(dic)
    

ans = prob()
print(ans)