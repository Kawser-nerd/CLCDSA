from __future__ import generators
from numpy import *
from time import time
import unittest

import psyco
psyco.full()

MAXSIZE=100

  

def handle_case(path):
  board = zeros((4*MAXSIZE+3, 4*MAXSIZE+3))
  pos = (0,0)
  dir = (0,1)
  for (S,L) in path:
    for i in range(0,L):
 #     print S
      for c in S:
        if c=='F':
          pos = (pos[0]+dir[0], pos[1]+dir[1])          
          board[pos[0]+2*MAXSIZE,pos[1]+2*MAXSIZE]=1
#          print pos
          pos = (pos[0]+dir[0], pos[1]+dir[1])
        if c=='L':
          dir = (-dir[1], dir[0])
        if c=='R':
          dir = (dir[1], -dir[0])
      
  res = 0
  inside = False
  pocketpoints = zeros((2*MAXSIZE+1, 2*MAXSIZE+1))
  for x in range(0, 2*MAXSIZE+1):
    lasty = -1
    for y in range(0, 2*MAXSIZE+1):
      if not inside:
        if board[2*x+1,2*y]==1:
          if lasty!=-1:
            for y1 in range(lasty, y):
              pocketpoints[x,y1]=1
              res = res +1
#              print (x,y1)
          inside = True   
#          print "Inside start" +str((x,y))
      else:
        if board[2*x+1,2*y]==1:
          lasty = y
          inside = False
 #         print "Inside stop" +str((x,y))
          
  inside = False
      
  for y in range(0, 2*MAXSIZE+1):
    lastx = -1
    for x in range(0, 2*MAXSIZE+1):
      if not inside:
        if board[2*x,2*y+1]==1:
          if lastx!=-1:
            for x1 in range(lastx, x):
              if pocketpoints[x1,y]==0:
                res=res+1
#                print (x1,y)
              pocketpoints[x1,y]=1
          inside = True   
      else:
        if board[2*x,2*y+1]==1:
          lastx = x
          inside = False
#  print pocketpoints
  return res
  
        
        

def main():
  prefix = "A-small-attempt0"
  input = open(prefix+".in")
  output = open(prefix+".out","w")
  line = input.readline()
  totstart = time()
  for case in range(1,1+int(line)):
      start = time()
      
      L=int(input.readline().strip())
      path=[]
      data = ""
      line = []
      while len(line)<2*L:
        data = data +" "+ input.readline().strip()
        line = data.split()
      print line
      print len(line)
      for i in range(0,L):
        (S,T) = (line[2*i], int(line[2*i+1]))
        path.append((S,T))        
      print path
      res = handle_case(path)
      
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
    res = handle_case([("FFFR",4)])
    self.assertEquals(0, res)
    
  def testcase2(self):
    res = handle_case([("F", 6), ("R", 1), ("F" ,4), ("RFF", 2), ("LFF" ,1),
("LFFFR", 1), ("F", 2), ("R", 1), ("F", 5)])
    self.assertEquals(4, res)