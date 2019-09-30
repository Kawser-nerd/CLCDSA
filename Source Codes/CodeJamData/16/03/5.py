print "Case #1:"

n=32
j=500

for i in range(j):
  x = str(bin(i))[2:]
  y = '0' * ((n/2 - 2) - len(x)) + x
  
  s = '1' + y + '11' + y + '1'
  for k in range(2,11):
    s += ' ' + str(k**(n/2) + 1)
  print s
