#f = file("test2.in", "r")
#f = file("/Users/finn/Downloads/B-small-attempt0.in", "r")
#f = file("/Users/finn/Downloads/B-small-attempt1.in", "r")
#f = file("/Users/finn/Downloads/B-small-attempt2.in", "r")
f = file("/Users/finn/Downloads/B-large.in", "r")
#of = file("B-small.out", "w")
of = file("B-large.out", "w")
lines = f.readlines()

cases = int(lines[0])
line = 1
for case in range(cases):
	input = lines[line].split(" ");
	l = int(input[0])
	p = int(input[1])
	c = int(input[2])
	line += 1

	
	test = l
	steps = 0
	while test < p:
		test *= c
		steps += 1
		
	loads = 0
	totest = steps - 1
	print "totest", totest
	while totest > 0:
		totest /= 2
		loads += 1
		
	print "loads", loads
	of.write("Case #%d: %d\n" % (case + 1, loads))
