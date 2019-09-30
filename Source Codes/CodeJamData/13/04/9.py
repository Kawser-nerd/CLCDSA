#!/usr/bin/python
#
# Treasure - Google Code Jam 2013 Qualifying D

import sys

inp=sys.stdin
cases=int(inp.readline())

def whichchestscaniopen(keyshave,cheststoopen):
  canopen=[]
  for i in cheststoopen:
    keyneeded=openchestswithkey[i]
    if keyshave[keyneeded]>0:
      canopen.append(i)
  return canopen

def isitstillfeasible(keyshave,cheststoopen):
  newkeys=[]
  for keyno in xrange(1,201):
    if keyshave[keyno]>0:
      newkeys.append(keyno)
  reachedkeys=newkeys[:]
  openedchests=0
  while len(newkeys)>0:
    dokeys=newkeys
    newkeys=[]
    for chestno in cheststoopen:
      if openchestswithkey[chestno] in dokeys:
        openedchests+=1
        for k in chests[chestno]:
          if k not in reachedkeys:
            reachedkeys.append(k)
            newkeys.append(k)
  if openedchests<len(cheststoopen):
    return False
  else:
    return True

for case in xrange(cases):
  #Read in case
  config=inp.readline().strip().split()
  numinitialkeys=int(config[0])
  numchests=int(config[1])
  cheststoopen=list(range(numchests))
  initialkeys=[0]*201
  keynums=inp.readline().strip().split()
  for i in xrange(numinitialkeys):
    keynum=int(keynums[i])
    initialkeys[keynum]+=1
  chests=[]
  openchestswithkey=[]
  for i in xrange(numchests):
    chestconfig=inp.readline().strip().split()
    openchestswithkey.append(int(chestconfig[0]))
    numkeys=int(chestconfig[1])
    keysinchest=[]
    for j in xrange(numkeys):
      keysinchest.append(int(chestconfig[j+2]))
    chests.append(keysinchest)
  #Make sure there are enough keys in the whole thing.  
  keysrequired=[0]*201
  for k in openchestswithkey:
    keysrequired[k]+=1
  keysavailable=initialkeys[:]
  for ch in chests:
    for k in ch:
      keysavailable[k]+=1
  ok=1
  for i in xrange(1,201):
    if keysrequired[i]>keysavailable[i]:
      ok=0
      break
  if ok==0:
    print "Case #"+repr(case+1)+": IMPOSSIBLE"
    continue
  #Make sure there is a feasible path to open every chest
  if not isitstillfeasible(initialkeys,cheststoopen):
    print "Case #"+repr(case+1)+": IMPOSSIBLE"
    continue
  #Process case with greedy algorithm and depth-first search.
  cheststack=[]
  #Determine which chests can be opened now
  keyshave=initialkeys[:]
  canopen=whichchestscaniopen(keyshave,cheststoopen)
  if len(canopen)==0:
    #Can't even open the first chest
    print "Case #"+repr(case+1)+": IMPOSSIBLE"
    continue
  #Open the first of these chests, and put the current case on the stack.
  #There is a trickiness to this. When I want to back out of this case, I get
  #back the key I would have used here, and use some other key instead, and
  #likewise I put back any keys acquired from inside that chest and get them
  #from another one. Likewise for cheststoopen. So neither of these are updated
  #before storing them on the stack. Make sure to make copies of lists.
  cheststack.append([canopen[0],canopen[1:],keyshave[:],cheststoopen[:]])
  keyshave[openchestswithkey[canopen[0]]]-=1
  del cheststoopen[cheststoopen.index(canopen[0])]
  for k in chests[canopen[0]]:
    keyshave[k]+=1
  #Now I want to iterate this. Repeatedly:
  # * If all chests are open, report the answer and stop.
  # * Try to open a chest. If I can open any chest, open the first one possible
  #   and add it to the stack like I did above.
  # * If I can't open any chests, backtrack to the last step on the stack and
  #   open the next chest there. If that one is also out of cases, repeat
  #   down the stack until I find one I can open, or the stack is empty.
  #   If the stack becomes empty, report impossible and quit.
  while True:
    if len(cheststoopen)==0:
      #Done! The stack shows the correct order to open the chests.
      outputstr="Case #"+repr(case+1)+":"
      for ch in cheststack:
        outputstr+=" "+repr(ch[0]+1)
      print outputstr
      break
    else:
      if isitstillfeasible(keyshave,cheststoopen):
        canopen=whichchestscaniopen(keyshave,cheststoopen)
        #Open the first chest in the list and add it to the stack
        cheststack.append([canopen[0],canopen[1:],keyshave[:],cheststoopen[:]])
        keyshave[openchestswithkey[canopen[0]]]-=1
        del cheststoopen[cheststoopen.index(canopen[0])]
        for k in chests[canopen[0]]:
          keyshave[k]+=1
      else:
        #back out the last chest choice and try the next one.
        while len(cheststack)>0 and len(cheststack[-1][1])==0:
          #Pop from stack a move with no alternatives
          del cheststack[-1]
        if len(cheststack)==0:
          #No moves left, so case is impossible
          print "Case #"+repr(case+1)+": IMPOSSIBLE"
          break
        #restore state from last stack case, making copies
        keyshave=cheststack[-1][2][:]
        cheststoopen=cheststack[-1][3][:]
        #take next chest choice from that case
        cheststack[-1][0]=cheststack[-1][1][0]
        del cheststack[-1][1][0]
        #update key and chest inventory after opening that chest
        keyshave[openchestswithkey[cheststack[-1][0]]]-=1
        del cheststoopen[cheststoopen.index(cheststack[-1][0])]
        for k in chests[cheststack[-1][0]]:
          keyshave[k]+=1

      
