import sys

inputFile = sys.stdin
count = int(inputFile.readline())

for lineno in xrange(1, count+1):
  R, k, N = map(int, inputFile.readline().split())
  groups = map(int, inputFile.readline().split())

  transitions = {}
  for gi in xrange(len(groups)):
    people = 0
    curgi = gi
    while curgi < gi + len(groups):
      curGroup = groups[curgi % len(groups)]
      if people + curGroup > k: 
        break
      people += curGroup
      curgi += 1
      
    next = curgi % len(groups)
    money = people
    transitions[gi] = (next, money)

  state = {}
  curgi = 0
  money = 0
  i = 0
  while i < R:
    next, newmoney = transitions[curgi]
    
    if state.has_key(curgi):
      # we looped. Skip as many as you can
      loopStartMoney, loopStartDistance = state[curgi]
      moneyMade = money - loopStartMoney
      distance = i - loopStartDistance
      
      loops = (R - i) / distance
      money += loops * moneyMade
      i += loops * distance
      state = {}
      continue
    else:
      state[curgi] = money, i

      money += newmoney
      curgi = next
      i += 1
  
  print "Case #%d:" % lineno,
  print money
