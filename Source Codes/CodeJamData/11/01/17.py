import sys

data = [l.strip() for l in open("infile", "r").readlines()]
out = open("outfile", "w")

class robot:
  def __init__(self, col, casedata):
    self.color = col
    self.pos = 1
    self.cindex = -2
    self.nextgoal = 'START'
    self.findnextgoal(casedata)
  def movetowardgoal(self):
    if self.nextgoal == 'DONE':
      pass
    elif self.pos < self.nextgoal:
      self.pos += 1
    elif self.pos > self.nextgoal:
      self.pos -= 1
    else: # no need to move
      pass
  def findnextgoal(self, casedata):
    self.cindex += 2
    while self.cindex < len(casedata) and casedata[self.cindex] != self.color:
      self.cindex += 2
    try:
      self.nextgoal = int(casedata[1 + self.cindex])
    except:
      self.nextgoal = 'DONE'    

ncases = int(data.pop(0))
for case in range(ncases):
  casedata = data.pop(0).split(' ')
  numreqs = casedata.pop(0)
  timetaken = 0
  orange = robot('O', casedata)
  blue = robot('B', casedata)
  while (orange.nextgoal != 'DONE' or blue.nextgoal != 'DONE'):
    timetaken += 1
    if orange.cindex < blue.cindex:
      if orange.nextgoal == orange.pos:
        orange.findnextgoal(casedata)
      else:
        orange.movetowardgoal()
      blue.movetowardgoal()
    elif blue.cindex < orange.cindex:
      if blue.nextgoal == blue.pos:
        blue.findnextgoal(casedata)
      else:
        blue.movetowardgoal()
      orange.movetowardgoal()
    else: # shouldn't happen
      sys.exit()  
  out.write("Case #" + str(case+1) + ": " + str(timetaken) + "\n")
 
