with open('/home/gauravjs/Documents/Google Code Jam/2016Q/D-large.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()

for i in range(cases):
  k,c,s=lines[i].strip().split(' ')
  k = int(k)
  c = int(c)
  s = int(s)

  if c * s < k:
    print "Case #" + str(i+1) + ": IMPOSSIBLE"
  else:
    nums = []
    for j in range(0,k,c):
      n=j
      for l in range(1, c):
        n *= k
        n += min(j + l, k-1)
      nums.append(n + 1)

    print "Case #" + str(i+1) + ": " + ' '.join([str(x) for x in nums])
