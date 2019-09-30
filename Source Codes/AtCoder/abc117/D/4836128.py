import math
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
                w = cmt + ': ' + str(x)
            else:
                w = str(x)
            print(w)
        return x
def prob(): 
    d = Debug()
    d.off()
    N, K = getIntList()
    d.dmp((N, K), 'N, K')
    A = getIntList()
    d.dmp((A), 'A')
    if K == 0:
        x = 0
    else:
        lg = int(math.log2(K))
        mask = 1 << lg
        x = 0
        d.dmp(x,'x')
        lessK = False  # x<K???
        while mask > 0:
            cz, co = 0, 0
            for i in range(N):
                if A[i] & mask == 0:
                    cz += 1
                else:
                    co += 1
            if cz > co:
                if K & mask or lessK:
                    x += mask
            if (x & mask == 0) and mask & K:
                lessK = True
            mask >>= 1
            d.dmp((mask,x),'mask,x')
    d.dmp((x),'x')
    ans = 0
    for i in range(N):
        d.dmp((x ^ A[i]),'x ^ A[i]')
        ans += x ^ A[i]
    return ans


ans = prob()
print(ans)