with open('/home/gauravjs/Documents/Google Code Jam/2016Q/B-large.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()

for i in range(cases):
  n=0
  if lines[i][-2] == '-':
    n +=1
  s=lines[i][-2]
  for j in range(len(lines[i])-3, -1, -1):
    if lines[i][j] != s:
      s=lines[i][j]
      n+=1
  print "Case #" + str(i+1) + ": " + str(n)
