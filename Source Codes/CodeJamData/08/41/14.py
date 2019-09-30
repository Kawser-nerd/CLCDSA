import unittest

import psyco
psyco.full()

IMPOSSIBLE=99999999

class Solver():
  def __init__(self,M,values,changeable):
    self.M = M
    self.values = values
    self.changeable = changeable
    self.mem = {}

  def min(self, i, val, type):
    if type==0:
      # or
      if val==0:
        l = self.dp(2*i,0)
        r = self.dp(2*i+1,0)
        if l==IMPOSSIBLE or r==IMPOSSIBLE:
          res = IMPOSSIBLE
        else:
          res = l+r
      else:
        l = self.dp(2*i,1)
        r = self.dp(2*i+1,1)
        if l==IMPOSSIBLE and r==IMPOSSIBLE:
          res = IMPOSSIBLE
        else:
          res = min(l,r)
    if type==1:
      # and
      if val==0:
        l = self.dp(2*i,0)
        r = self.dp(2*i+1,0)
        if l==IMPOSSIBLE and r==IMPOSSIBLE:
          res = IMPOSSIBLE
        else:
          res = min(l,r)
      else:
        l = self.dp(2*i,1)
        r = self.dp(2*i+1,1)
        if l==IMPOSSIBLE and r==IMPOSSIBLE:
          res = IMPOSSIBLE
        else:
          res = l+r
    return res
    
  def dp(self,i, val):
    if (i,val) in self.mem:
      return self.mem[i,val]
    if i > (self.M-1)/2:
      if self.values[i]==val:
        return 0
      else:
        return IMPOSSIBLE
  
    res = self.min(i, val, self.values[i])
    if i in self.changeable:
      c = self.min(i,val, 1-self.values[i])
      res = min(c+1, res)

    self.mem[i,val]= res
    return res
                  

def handle_case(M,V,values, changeable):
  s = Solver(M, values, changeable)
  return s.dp(1,V)

def main():
  prefix = "A-large"
  input = open(prefix+".in")
  output = open(prefix+".out","w")
  line = input.readline().strip()
  for case in range(1,1+int(line)):
      line = input.readline().strip()
      (M,V)= map(int,line.split())
      values = [0]
      changeable = []
      for i in range(0,(M-1)/2):
        (G,C) = map(int,input.readline().strip().split())
        values.append(G)
        if C == 1:
          changeable.append(i+1)
      for i in range(0,(M+1)/2):
        line = input.readline().strip()
        l = int(line)
        values.append(l)
        
      res = handle_case(M,V, values, changeable)
      if res>=IMPOSSIBLE:
        print "Case #" + str(case) + ": IMPOSSIBLE"
        output.write("Case #" + str(case) + ": IMPOSSIBLE"+"\n")
      else:
        print "Case #" + str(case) + ": " + str(res)
        output.write("Case #" + str(case) + ": " + str(res)+"\n")
  output.close()
  
if __name__ == "__main__":
  main()
  
class TestCases(unittest.TestCase):  
  def testcase1(self):
    res = eval([1,2,3,4,5], " +  ")
    self.assertEquals(357, res)