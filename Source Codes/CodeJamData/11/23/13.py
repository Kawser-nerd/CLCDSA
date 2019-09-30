data = [l.strip() for l in open("infile", "r").readlines()]
out = open("outfile", "w")

def check(rooms, colorset):
  mincolorsinaroom = 99999
  for r in rooms:
    colorsinroom = []
    for v in r:
      if colorset[v] not in colorsinroom:
        colorsinroom.append(colorset[v])
    if len(colorsinroom) < mincolorsinaroom:
      mincolorsinaroom = len(colorsinroom)
  return mincolorsinaroom

numcases = int(data.pop(0))
for case in range(numcases):
  colornum = 'error'
  colorlist = ''
  n, m = [int(i) for i in data.pop(0).split(' ')]
  starts = [int(i) for i in data.pop(0).split(' ')]
  ends = [int(i) for i in data.pop(0).split(' ')]
  rooms = [range(1, n+1)]
  while len(starts) > 0:
    s = starts.pop(0)
    e = ends.pop(0)
    # only one room will have both s and e
    roomindex = 0
    while not ((s in rooms[roomindex]) and (e in rooms[roomindex])):
      roomindex += 1
    roomtodivide = rooms.pop(roomindex)
    spos = roomtodivide.index(s)
    epos = roomtodivide.index(e)
    if spos > epos:
      temp = epos
      epos = spos
      spos = temp
    rooms.append(roomtodivide[spos:epos+1])
    rooms.append(roomtodivide[epos:] + roomtodivide[:spos+1])
  # numflavors can't be larger than smallest room size
  maxpillars = 99999
  for r in rooms:
   if len(r) < maxpillars:
      maxpillars = len(r)
  # BRUTE FORCE
  bestmc = 0
  bestclist = []
  for i in range(maxpillars**n):
    colorset = ['dummy'] + [0]*n       
    j = 1
    icopy = i        
    while icopy > 0:
      colorset[j] = icopy % maxpillars
      icopy /= maxpillars
      j += 1
    mc = check(rooms, colorset)
    if mc > bestmc:
      bestmc = mc
      bestclist = colorset
    if bestmc == maxpillars:
      break
  colornum = bestmc
  for i in bestclist[1:]:
    colorlist += str(i+1) + ' '
  out.write("Case #" + str(case+1) + ": " + str(colornum) + "\n")
  out.write(colorlist + "\n")

