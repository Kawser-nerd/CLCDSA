limit = 1000000

with open('/home/gauravjs/Documents/Google Code Jam/2016Q/A-large.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()
inputs=[]
for i in range(cases):
  n=int(lines[i])
  m=n
  digits = set()
  while (m < n * limit) and len(digits) < 10:
    q=m
    while q>0:
      digits.add(q%10)
      q=q/10
    m+=n
  if len(digits) == 10:
    print "Case #" + str(i+1) + ": " + str(m-n)
  else:
    print "Case #" + str(i+1) + ": INSOMNIA"
