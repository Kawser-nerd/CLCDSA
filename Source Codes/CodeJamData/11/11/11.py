infile = open('as.in')
num_cases = readint()
for iter in range(num_cases):
  case = infile.readline().split()
  case = [(int(case[i]=='B'), int(float(case[i+1]))) for i in range(1,2*int(case[0]),2)]
  x, y, t = 1, 1, 0
  xt, yt, = 1, 1
  while len(case) > 0:
    z = case.pop(0)
    if z[0]:
      d = max(0, abs(z[1] - x) - (t - xt))
      t = t + d + 1
      x = z[1]
      xt = t      
    else:
      d = max(0, abs(z[1] - y) - (t - yt))
      t = t + d + 1
      y = z[1]
      yt = t
  print "Case #" + str(iter) + ": " + str(t-1)