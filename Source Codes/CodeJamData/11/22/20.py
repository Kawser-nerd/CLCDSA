#import psyco
#psyco.full()

class memoize:
  def __init__(self, function):
    self.function = function
    self.memoized = {}

  def __call__(self, *args):
      if args not in self.memoized:
        self.memoized[args] = self.function(*args)
      return self.memoized[args]

  def clear(self):
      self.memoized = {}

def gcd(a,b):
    while b: a,b = b, a%b
    return a
    
def abs(x):
    if x<0: return -x
    return x
    
def maxarg(f, args):
    max=-1
    for a in args:
        x = f(a)
        if x>max:
            best=a
            max=x
    return best

def solve():
    for i in range(c):
        for j in range(i,c):
            a=p[j][0]-p[i][0]
            b = D*(sum(p[k][1] for k in range(i,j+1))-1)
            x = float(b- a)/2
            #print i,j,"->",a,b,"=",x
            yield x

from time import time
if __name__ == "__main__":
    def getInts(): return map(int, input.readline().rstrip('\n').split(' '))
    def getFloats(): return map(float, input.readline().rstrip('\n').split(' '))
    def getMatrix(rows): return [getInts() for _ in range(rows)]
    def getString(): return input.readline().rstrip('\n')
    input, output = open("in", "r"), open('output', 'w')
    start_time=time()
    for case in range(1, int(input.readline()) + 1):
        c,D = getInts()
        p=[]
        for _ in range(c):
            p.append(tuple(getInts()))
        #print D,p
        ans=max(x for x in solve())
        s="Case #%d: %f\n" % (case,  ans)
        print s
        output.write(s)

    print time()-start_time
