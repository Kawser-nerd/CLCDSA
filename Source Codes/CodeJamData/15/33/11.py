T = int(raw_input())

for testcase in range(T):
  [c,d,v] = [int(x) for x in raw_input().split()]
  old_denominations = [int(x) for x in raw_input().split()]
  old_denominations.sort()
  cashmoneys = 0
  new_denominations = []
  while cashmoneys < v:
    if not old_denominations or old_denominations[0] > cashmoneys+1:
      new_denominations.append(cashmoneys+1)
      cashmoneys += c*(cashmoneys+1)
    else:
      while old_denominations and old_denominations[0] <= cashmoneys+1:
        cashmoneys += c*(old_denominations[0])
        old_denominations.pop(0)
  print "Case #%s: %s" % (testcase+1, len(new_denominations))
