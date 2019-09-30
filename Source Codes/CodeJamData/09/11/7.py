filename = 'A-small-attempt0'

f = open(filename + '.in', 'r')
lines = f.readlines()
f.close()

MAX_NUM = 1000000
HAPPY = [0]*11
for i in xrange(len(HAPPY)):
  HAPPY[i] = [-1] * MAX_NUM
  HAPPY[i][1] = 1

def radix(num, base):
  digits = []
  while num != 0:
    digits.append(num % base)
    num = num / base
  return digits

def ishappy(num, base):
  seen = {}
  while True:
    if HAPPY[base][num] != -1:
      for x in seen.keys():
        HAPPY[base][x] = HAPPY[base][num]
      return HAPPY[base][num]
    tot = 0
    seen[num] = True
    for digit in radix(num, base):
      tot += digit * digit
    if tot in seen:
      for x in seen.keys():
        HAPPY[base][x] = 0 
      return 0
    num = tot

out = open(filename + '.out', 'w')
T = int(lines[0].strip())
case = 1
for line in lines[1:]:
  bases = [int(x) for x in line.strip().split(' ')]
  print bases
  printed = False
  for num in xrange(2, MAX_NUM):
    found = True
    for base in bases:
      if ishappy(num, base) == 0:
        found = False
        break
    if found:
      printed = True
      print 'Case #%d: %d' % (case, num)
      out.write('Case #%d: %d\n' % (case, num))
      break
  if printed == False:
    print "COULDN'T FIND ANSWER FOR %d" % str(bases)
  case += 1

out.close()
