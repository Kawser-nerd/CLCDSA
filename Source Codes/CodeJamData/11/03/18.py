data = [l.strip() for l in open("infile", "r").readlines()]
out = open("outfile", "w")  

ncases = int(data.pop(0))
for case in range(ncases):
  numcandies = int(data.pop(0))
  candies = [int(c) for c in data.pop(0).split(' ')]
  # go through candy list, finding sum, minimum, and xor sum.
  truesum = 0
  xorsum = 0
  minimum = candies[0]
  for i in candies:
    truesum += i
    xorsum ^= i
    if i < minimum:
      minimum = i
  ans = 'NO'
  if xorsum == 0:
    ans = str(truesum - minimum)
  out.write("Case #" + str(case+1) + ": " + ans + "\n")
   
