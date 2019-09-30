ntest = int(raw_input())
for itc in range(ntest):
  print 'Case #%d:' % (itc+1),
  peta = []
  for _ in range(4):
    peta.append(raw_input())
  raw_input()
  # check if x win
  tochecks = ['O', 'X']
  done = 0
  for tocheck in tochecks:
    newpeta = [x.replace('T', tocheck) for x in peta]
    iswin = 0
    iswin |= tocheck * 4 in newpeta
    iswin |= [tocheck] * 4 in map(list, zip(*newpeta))
    iswin |= tocheck * 4 == newpeta[0][0] + newpeta[1][1] + newpeta[2][2] + newpeta[3][3]
    iswin |= tocheck * 4 == newpeta[3][0] + newpeta[2][1] + newpeta[1][2] + newpeta[0][3]
    if iswin:
      done = 1
      print '{0} won'.format(tocheck)
  if not done:
    if '.' not in ''.join(peta):
      print 'Draw'
    else:
      print 'Game has not completed'
