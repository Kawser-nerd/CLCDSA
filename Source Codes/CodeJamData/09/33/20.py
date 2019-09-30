import psyco
psyco.full()

class memoize:
  def __init__(self, function):
    self.function = function
    self.memoized = {}

  def __call__(self, *args):
      if args not in self.memoized:
        self.memoized[args] = self.function(*args)
      return self.memoized[args]

def all_perms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in all_perms(str[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + str[0:1] + perm[i:]

def solve(P, Q):
    #print P, Q, ":"
    min=P*len(Q)
    for perm in all_perms(Q):
        prisons=[True]*(P+1)
        sum=0
        for rel in perm:
            prisons[rel]=False
            i=rel+1
            while i<=P and prisons[i]:
                sum+=1
                i+=1
            i=rel-1
            while i>0 and prisons[i]:
                sum+=1
                i-=1
            #print rel, "->", sum
        #print perm, sum
        if sum<min:
            min=sum
    return min

from time import time
if __name__ == "__main__":
    def getInts():
        return map(int, data.readline().rstrip('\n').split(' '))
    start_time=time()
    output = open('d:/gcj/output', 'w')
    data = open("d:/gcj/in", "r")
    Cases = int(data.readline())
    for case in range(1, Cases + 1):
        P, _ = getInts()
        s="Case #%d: %d" % (case, solve(P, getInts()))
        print(s)
        output.write(s+"\n")
            
    print time()-start_time

    