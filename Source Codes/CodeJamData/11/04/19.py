data = [l.strip() for l in open("infile", "r").readlines()]
out = open("outfile", "w")  

ncases = int(data.pop(0))
for case in range(ncases):
  numelements = int(data.pop(0))
  # print "Round " + case ". FIGHT!!!!!!!!!!!"
  elements = [int(s) for s in data.pop(0).split(' ')]
  inwrongplace = 0
  for i in range(len(elements)):
    if elements[i] != i+1:
      inwrongplace += 1
  # on average, each pound that holds all correct elements in place
  # will add 1 more correctly-placed element, so average # of pounds
  # equals elements initially in the wrong place.
  out.write("Case #" + str(case+1) + ": " + str("%.6f" % inwrongplace) + "\n")

# print "FINISH HIM!!!!!!!!!!!!!!"
