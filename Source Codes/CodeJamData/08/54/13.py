from __future__ import generators
from numpy import *
from time import time
import unittest

import psyco
psyco.full()

def dp(H,W,R,rocks,mem, x,y):
  if (x,y) in mem:
    return mem[(x,y)]
  if x==H and y==W:
    return 1
  if x>H or y>W:
    return 0
  if (x,y) in rocks:
    return 0
  res = (dp(H,W,R,rocks,mem, x+2,y+1) + dp(H,W,R,rocks,mem, x+1,y+2))%10007
  mem[(x,y)]=res
  return res 
  

def handle_case(H,W,R,rocks):
  return dp(H,W,R,rocks, {}, 1, 1)

def main():
  prefix = "D-small-attempt0"
  input = open(prefix+".in")
  output = open(prefix+".out","w")
  line = input.readline()
  totstart = time()
  for case in range(1,1+int(line)):
      start = time()
      
      (H,W,R)=map(int,input.readline().strip().split())
      rocks=[]
      for i in range(0,R):
        (r,c)=map(int,input.readline().strip().split())
        rocks.append((r,c))
      res = handle_case(H,W,R,rocks)
      
      end = time()
      print "Case #" + str(case) + ": " + str(res)
      output.write("Case #" + str(case) + ": " + str(res)+"\n")
      print "Took "+str(end-start)
  output.close()
  
  totend = time()  
  print "Total took "+str(totend-totstart)
  
if __name__ == "__main__":
  main()
  
class TestCases(unittest.TestCase):  
  def testcase1(self):
    res = handle_case(1,1,0,[])
    self.assertEquals(1, res)
    
  def testcase2(self):
    res = handle_case(4,4,1,[(2,1)])
    self.assertEquals(2, res)
  
  def testcase3(self):
    res = handle_case(3,3,0,[])
    self.assertEquals(0, res)