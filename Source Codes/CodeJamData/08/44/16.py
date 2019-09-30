from __future__ import generators
import unittest

import psyco
psyco.full()

def all_perms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in all_perms(str[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + str[0:1] + perm[i:]

def apply(k,p, S):
  res=""
  for i in range(0,len(S)/k):
    for j in range(0,k):
      res=res+S[i*k+p[j]]
  return res

def evaluate(z):
  res = 0
  prev = '0'
  for i in range(0,len(z)):
    if z[i]!=prev:
        res=res+1
    prev = z[i]
  return res
        
      

def handle_case(k,S):
  x = []
  min = 99999999
  for i in range(0,k):
    x.append(i)
  for perm in all_perms(x):
    z=apply(k,perm,S)
    t=evaluate(z)
    if t<min:
      min=t
  return min
    

def main():
  prefix = "D-small-attempt0"
  input = open(prefix+".in")
  output = open(prefix+".out","w")
  line = input.readline()
  for case in range(1,1+int(line)):
      k=int(input.readline().strip())
      S=input.readline().strip()
      res = handle_case(k,S)
      print "Case #" + str(case) + ": " + str(res)
      output.write("Case #" + str(case) + ": " + str(res)+"\n")
  output.close()
  
if __name__ == "__main__":
  main()
  
class TestCases(unittest.TestCase):  
  def testeval(self):
    res = handle_case(50,50,2500)
    self.assertEquals("", res)