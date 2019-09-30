from __future__ import generators
import unittest

import psyco
psyco.full()

IMP = (0,0,0,0,0,0)

def handle_case(N,M,A):
  for xb in range(1, N+1):
    for yc in range(1, M+1):
      for xc in range(1, N+1):
        t = A+xb*yc
        if t%xc == 0 and t/xc<=M:
          yb = t/xc
          return (0,0,xb,yb,xc,yc)
  for xb in range(1, N+1):
    for ya in range(1, M+1):
      for xc in range(1, N+1):
        t = A-xb*ya
        if t%xc == 0 and (t/xc+ya)<=M and (t/xc+ya)>=0:
          yb = t/xc+ya
          return (0,ya,xb,yb,xc,0)
  
  return IMP

def main():
  prefix = "B-small-attempt4"
  input = open(prefix+".in")
  output = open(prefix+".out","w")
  line = input.readline()
  for case in range(1,1+int(line)):
      (N,M,A)=map(int,input.readline().split())
      res = handle_case(N,M,A)
      if res == IMP:
        print "Case #" + str(case) + ": IMPOSSIBLE"
        output.write("Case #" + str(case) + ": IMPOSSIBLE\n")
      else:
        (xa,ya,xb,yb,xc,yc)=res
        strres = str(xa)+" "+str(ya)+" "+str(xb)+" "+str(yb)+" "+str(xc)+" "+str(yc)
        test = (xc-xa)*(yb-ya)-(xb-xa)*(yc-ya)
        if test!=A:
          print "Oops:"+ str(A)+"!="+str(test)
        if xa>N or xb>N or xc>N or ya>M or yb>M or yc>M:
          print "oops"
        if xa<0 or xb<0 or xc<0 or ya<0 or yb<0 or yc<0:
          print "oops"
        print "Case #" + str(case) + ": " + strres
        output.write("Case #" + str(case) + ": " + strres+"\n")
  output.close()
  
if __name__ == "__main__":
  main()
  
class TestCases(unittest.TestCase):  
  def testeval(self):
    res = handle_case(50,50,2500)
    self.assertEquals("", res)