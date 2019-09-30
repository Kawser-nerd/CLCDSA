import sys

inputFile = sys.stdin
count = int(inputFile.readline())

lineno = 1
for line in inputFile:
  n, k = line.split()
  n, k = int(n), int(k)

  print "Case #%d:" % lineno,
  total = pow(2, n)
  if k % total == total-1:
    print "ON"
  else: 
    print "OFF"

  lineno += 1

